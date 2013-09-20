#ifndef STRTOINT_H
#define STRTOINT_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

long long int strToInt(string src, int &error);
long long int strToIntHex(string src, int &error);

#endif
