/* 
 * File:   write.h
 * Author: froger
 *
 * Created on 7 kwiecień 2010, 14:47
 */

#ifndef _WRITE_H
#define	_WRITE_H

#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>

bool _write(int __fd, const void* __buf, size_t __n, int __flags=0);

#endif	/* _WRITE_H */

