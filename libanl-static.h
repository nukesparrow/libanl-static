#define internal_function \

#ifndef __set_errno
#define __set_errno(n) { errno = (n); }
#endif
