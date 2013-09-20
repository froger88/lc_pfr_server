#include "inttostr.h"

using namespace std;

string intToStr(int number)
{
  stringstream text;
  text << number;
  string x;
  text >> x;
  return x;
}

string intToStrHex(int number)
{
  stringstream text;
  text << hex<< number;
  string x;
  text >> x;
  return x;
}
