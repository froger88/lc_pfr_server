#include "ip.h"

bool operator == (IP &left, IP &right)
{
  if(left.text_IP == right.text_IP)
  {
    return true;
  }
  return false;
}
