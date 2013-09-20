#include "thread_connect.h"

#define _REENTRANT

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

using namespace std;

void* threadConnect(void *arg)
{
  long FD = reinterpret_cast<long> (arg);
  timespec TL;
  TL.tv_sec = 3; //seconds
  TL.tv_nsec = 0; //nano seconds

  timespec *timeout = &TL;

  fd_set readmask;
  FD_ZERO(&readmask);
  FD_SET(FD, &readmask);

  char ThreadBuffer[512];
  int th_str;
  //---------------/sekcja krytyczna\---------------
  while(1)
  {
    memset(ThreadBuffer, 0, 512);
    int nfound = pselect(sizeof (readmask)*8, &readmask, NULL, NULL, timeout, NULL);
    if(nfound == 0)
    {
      close(FD);
      pthread_exit(0);
    }
    else
    {
      th_str = read(FD, ThreadBuffer, 512);
      if((th_str == 0) || (th_str == -1))
      {
        close(FD);
        pthread_exit(0);
      }

      /**
      Odeslac policy-file-request
       **/
      string POLICY_STRING = "<?xml version=\"1.0\"?><cross-domain-policy><allow-access-from domain=\"*.web-anatomy.com\" to-ports=\"*\" /></cross-domain-policy>";
      int L = POLICY_STRING.length() + 1;
      char* answer = new char[L];
      for(int i = 0; i < L - 1; i++)
      {
        answer[i] = POLICY_STRING[i];
      }
      answer[L - 1] = NULL;
      _write(FD, answer, L);
      delete [] answer;
      answer = NULL;
    }
  }
}
