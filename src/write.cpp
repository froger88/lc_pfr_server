#include "write.h"

bool _write(int __fd, const void* __buf, size_t __n, int __flags) //flags default is 0
{
  const unsigned char* pbuf = (const unsigned char*) __buf;
  int length = __n;

  while(length)
  {
    int sent = send(__fd, pbuf, length, __flags);
    if(sent < 0)
    {
      return false;
    }
    length -= sent;
    pbuf += sent;
  }
  return true;
}
