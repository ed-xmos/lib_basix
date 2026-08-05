// Copyright 2026 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.
#ifndef _xc_safe_errno_h_
#define _xc_safe_errno_h_

#include <errno.h>

#ifdef __XC__
int * alias _safe_errno_addr(void);
#endif

#endif /* _xc_safe_errno_h_ */
