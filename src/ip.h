#ifndef IP_H
#define IP_H

#include "inttostr.h"
#include <iostream>
#include <string>
using namespace std;

/*
IP: AAA.BBB.CCC.DDD
*/

class IP
{
  public:
    inline IP();
    inline IP(int aaa, int bbb, int ccc, int ddd);
    inline IP(string text);
    inline IP(const IP &x);
    inline ~IP();

    inline void setIP(int aaa, int bbb, int ccc, int ddd);
    inline void setIP(string text);
    inline void setNumIP(int numip);

    inline string getIP() const;
    inline int getAAA() const;
    inline int getBBB() const;
    inline int getCCC() const;
    inline int getDDD() const;
    inline int getNumIP() const;

    inline IP& operator = (const IP &x);
    inline IP& operator = (const string text);
    inline IP& operator = (const int &numip);
    friend bool operator == (IP &left, IP &right);
  
  private:
    int AAA;
    int BBB;
    int CCC;
    int DDD;

    string text_IP;
    int numIP;
  protected:
};

inline IP::IP()
{
  AAA = 0;
  BBB = 0;
  CCC = 0;
  DDD = 0;
  text_IP = "";
  text_IP += intToStr(AAA);
  text_IP += "." + intToStr(BBB);
  text_IP += "." + intToStr(CCC);
  text_IP += "." + intToStr(DDD);
}

inline IP::IP(int aaa, int bbb, int ccc, int ddd)
{
  AAA = aaa;
  BBB = bbb;
  CCC = ccc;
  DDD = ddd;

  numIP = DDD+1000*CCC+1000000*BBB+1000000000*AAA;

  text_IP = "";
  text_IP += intToStr(AAA);
  text_IP += "." + intToStr(BBB);
  text_IP += "." + intToStr(CCC);
  text_IP += "." + intToStr(DDD);
}

inline IP::IP(string text)
{
  text_IP = text;
  AAA = -1;
  BBB = -1;
  CCC = -1;
  DDD = -1;
  numIP = -1;
}

inline IP::IP(const IP &x)
{
  AAA = x.AAA;
  BBB = x.BBB;
  CCC = x.CCC;
  DDD = x.DDD;

  numIP = x.numIP;

  text_IP = x.text_IP;  
}

inline IP::~IP()
{

}

inline void IP::setIP(int aaa, int bbb, int ccc, int ddd)
{
  AAA = aaa;
  BBB = bbb;
  CCC = ccc;
  DDD = ddd;
  numIP = DDD+1000*CCC+1000000*BBB+1000000000*AAA;

  text_IP = "";
  text_IP += intToStr(AAA);
  text_IP += "." + intToStr(BBB);
  text_IP += "." + intToStr(CCC);
  text_IP += "." + intToStr(DDD);
  return;
}

inline void IP::setIP(string text)
{
  text_IP = text;
  AAA = -1;
  BBB = -1;
  CCC = -1;
  DDD = -1;
  numIP = -1;
  return;
}

inline string IP::getIP() const
{
  return text_IP;
}

inline int IP::getAAA() const
{
  return AAA;
}

inline int IP::getBBB() const
{
  return BBB;
}

inline int IP::getCCC() const
{
  return CCC;
}

inline int IP::getDDD() const
{
  return DDD;
}

inline int IP::getNumIP() const
{
  return numIP;
}

inline IP& IP::operator = (const IP &x)
{
  AAA = x.AAA;
  BBB = x.BBB;
  CCC = x.CCC;
  DDD = x.DDD;

  numIP = DDD+1000*CCC+1000000*BBB+1000000000*AAA;

  text_IP = x.text_IP;
  return *this;
}

inline IP& IP::operator = (const int &numip)
{
  AAA = (numip/1000000000)%1000;
  BBB = (numip/1000000)%1000;
  CCC = (numip/1000)%1000;
  DDD = numip%1000;

  numIP = numip;

  text_IP = "";
  text_IP += intToStr(AAA);
  text_IP += "." + intToStr(BBB);
  text_IP += "." + intToStr(CCC);
  text_IP += "." + intToStr(DDD);
  return *this;
}

inline IP& IP::operator = (const string text)
{
  text_IP = text;
  
  AAA = -1;
  BBB = -1;
  CCC = -1;
  DDD = -1;
  numIP =-1;
  return *this;
}

inline void IP::setNumIP(int numip)
{
  numIP = numip;
  AAA = (numip/1000000000)%1000;
  BBB = (numip/1000000)%1000;
  CCC = (numip/1000)%1000;
  DDD = numip%1000;

  text_IP = "";
  text_IP += intToStr(AAA);
  text_IP += "." + intToStr(BBB);
  text_IP += "." + intToStr(CCC);
  text_IP += "." + intToStr(DDD);
  return;
}

#endif
