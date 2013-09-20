#ifndef THREAD_CONNECT_H
#define THREAD_CONNECT_H

#define _REENTRANT

#include <pthread.h>
#include <iostream>
#include <string>
#include <cstring>

#include <sys/types.h>
#include "write.h"

void* threadConnect(void *arg);

#endif
