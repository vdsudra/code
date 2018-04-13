#ifndef _IOCTL_H
#define _IOCTL_H

#define MY_MAGIC 'V'
/*
_IO(type, nr)
_IOW(type, nr, data)
_IOR(type, nr, data)
_IOWR(type, nr, data)

*/


#define FILL_ZERO _IO(MY_MAGIC, 1)
#define FILL_CHAR _IOW(MY_MAGIC, 2, char)
#define SET_SIZE _IOW(MY_MAGIC, 3, int)
#define GET_SIZE _IOR(MY_MAGIC, 4, int)
#define MAX_CMDS 4

#endif
