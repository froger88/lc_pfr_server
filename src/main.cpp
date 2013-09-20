#include <netinet/tcp.h>
#include "main.h"

using namespace std;

#define MAX_GLOBAL_BAN_LIST 100

int main(int argc, char** argv)
{
    string CROSS = "    ++\n    ++\n    ++\n++++++++++\n++++++++++\n    ++\n    ++\n    ++\n    ++\n    ++\n    ++\n    ++";
  cout << CROSS<<endl; //krzyza nic nie ruszy @wydarzenia z sierpnia 2010
  int MaxThread = 10000;
  int MaxWait = 50;
  int Port = 843;
  int SockFD;
  long NewSockFD[1000000];

  pthread_t Thread, ThreadGuard;
  pthread_attr_t AttrThread, AttrThreadGuard;
  size_t ClientLength;
  char Buffer[512];
  sockaddr_in ServerAddress;
  sockaddr ClientAddress;

  cout << "Policy-File-Request server v.1.020 by Froger\n" << endl;
  cout << "Port: " << Port << endl;
  cout << "Max Wait Clients: " << MaxWait << endl;
  cout << "Max Threads: " << MaxThread << endl;

  pthread_setconcurrency(MaxThread + 1);
  pthread_attr_init(&AttrThread);
  pthread_attr_setdetachstate(&AttrThread, PTHREAD_CREATE_DETACHED);

  pthread_attr_init(&AttrThreadGuard);
  pthread_attr_setdetachstate(&AttrThreadGuard, PTHREAD_CREATE_DETACHED);

  int cpid1 = (int) pthread_create(&ThreadGuard, &AttrThreadGuard, threadGuard, NULL);
  if(cpid1 != 0)
  {
    return EXIT_FAILURE;
  }

  SockFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if(SockFD < 0)
  {
    cout << "Server start fail" << endl;
    return 0;
  }
  int flags;
  /* Set socket to non-blocking */
  if((flags = fcntl(SockFD, F_GETFL, 0)) < 0)
  {
    close(SockFD);
    return EXIT_FAILURE;
  }

  if(fcntl(SockFD, F_SETFL, flags | O_NONBLOCK) < 0)
  {
    close(SockFD);
    return EXIT_FAILURE;
  }
  int mainsocketoption = 1;
  setsockopt(SockFD, IPPROTO_TCP, O_NDELAY, &mainsocketoption, sizeof (int));

  memset(Buffer, 0, 512);


  ServerAddress.sin_family = AF_INET;
  ServerAddress.sin_addr.s_addr = INADDR_ANY;
  ServerAddress.sin_port = htons(Port);

  if(bind(SockFD, (sockaddr *) & ServerAddress, sizeof (ServerAddress)) < 0)
  {
    cout << "Error while binding" << endl;
    return EXIT_FAILURE;
  }
  listen(SockFD, MaxWait);
  cout << "Server start OK" << endl;
  int count = 0;
  while(1)
  {
    bool ok = true;
    if(count >= 1000000)
    {
      count = 0;
    }
    ClientLength = sizeof (ClientAddress);

    int nfound = 0;
    fd_set readmask;
    FD_ZERO(&readmask);
    FD_SET(SockFD, &readmask);
    nfound = pselect(sizeof (readmask)*8, &readmask, &readmask, &readmask, NULL, NULL);
    if(nfound > 0)
    {
      int fdtmp = accept(SockFD, (sockaddr *) & ClientAddress, (socklen_t*) & ClientLength);
      NewSockFD[count] = fdtmp;
      int flags;
      if((flags = fcntl(NewSockFD[count], F_GETFL, 0)) < 0)
      {
        close(NewSockFD[count]);
        ok = false;
      }
      if(fcntl(NewSockFD[count], F_SETFL, flags | O_NONBLOCK) < 0 && ok)
      {
        close(NewSockFD[count]);
        ok = false;
      }
      if(ok)
      {
        setsockopt(NewSockFD[count], SOL_SOCKET, SO_REUSEADDR, &mainsocketoption, sizeof (int));
        setsockopt(NewSockFD[count], IPPROTO_TCP, O_NDELAY, &mainsocketoption, sizeof (int));

        if(NewSockFD[count] >= 0)
        {
          int cpid = (int) pthread_create(&Thread, &AttrThread, threadConnect, (void*) NewSockFD[count]);
          if(cpid != 0)
          {
            close(NewSockFD[count]);
          }
        }
        count++;
      }
    }
  }
  return 0;
}
