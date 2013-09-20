/* 
 * File:   thread_guard.h
 * Author: froger
 *
 * Created on 5 październik 2009, 19:12
 */

#ifndef _THREAD_GUARD_H
#define	_THREAD_GUARD_H

#define _REENTRANT

#include <iostream>
#include <cstring>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "main.h"

void* threadGuard(void *arg);
#endif	/* _THREAD_GUARD_H */
