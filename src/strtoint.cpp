#include "strtoint.h"

using namespace std;

 long long int strToInt(string src, int &error)
{
  int number = 0;
  string tmp = src;
  stringstream text;
  text << tmp;
  text >> number;
  
  return number;
}

 long long int strToIntHex(string src, int &error)
{
  int number = 0;
  string tmp = src;
  stringstream text;
  text << tmp;
  text >>(hex)>> number;
  
  return number;
}