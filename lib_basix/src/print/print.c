/*************************************************************************
 *
 * XMOS print library
 *
 *   XC File : print.xc
 *   Author  : Douglas Watt
 *          +: Richard Osborne
 *
 *************************************************************************/
/*
 * Copyright (c) 2006-2008 XMOS Ltd.
 *
 * Copyright Notice
 *
 *************************************************************************/

#include <syscall.h>
#include <limits.h>
#include <string.h>

#include <basix/print.h>

// Helper functions
static void reverse_array(char buf[], unsigned size);

static const char newline[1] = {'\n'};

int printchar(char value)
{
  char tmp[1];
  tmp[0] = value;
  return _write(FD_STDOUT, tmp, 1);
}

int printcharln(char value)
{
  char tmp[2];
  tmp[0] = value;
  tmp[1] = '\n';
  return _write(FD_STDOUT, tmp, 2);
}

static void reverse_array(char buf[], unsigned size)
{
  int begin = 0;
  int end = size - 1;
  int tmp;
  for (;begin < end;begin++,end--) {
    tmp = buf[begin];
    buf[begin] = buf[end];
    buf[end] = tmp;
  }
}

static const char digits[] = "0123456789ABCDEF";

#define GLUE(a,b)       a ## b
#define SUFFIX(a,b)     GLUE(a,b)

#define PRINTLN_BODY(call) \
  int tmp; \
  int written = call; \
  if (written < 0) \
    return written; \
  tmp = _write(FD_STDOUT, newline, 1); \
  if (tmp < 0) \
    return tmp; \
  else \
    written += tmp; \
  return written;

/*
 * There is at most one digit per bit. So the maximum buffer needed is equal to
 * the number of bits in an int.
 */
#define DEFINE_PRINT_UINT(name, type) \
static int SUFFIX(print,SUFFIX(name, _base_aux))(type n, unsigned base) \
{ \
  char buf[CHAR_BIT * sizeof(type)]; \
  int i = 0; \
  while (n > 0) { \
    type next = n / base; \
    type cur  = n % base; \
    buf[i] = digits[cur]; \
    i += 1; \
    n = next; \
  } \
  reverse_array(buf, i); \
  return _write(FD_STDOUT, buf, i); \
} \
static int SUFFIX(print,SUFFIX(name, _base))(type n, unsigned base) \
{ \
  if (n == 0) \
    return printchar('0'); \
  else \
    return SUFFIX(print,SUFFIX(name, _base_aux))(n, base); \
} \
int SUFFIX(print,name)(type n) \
{ \
  return SUFFIX(print,SUFFIX(name, _base))(n, 10); \
} \
int SUFFIX(SUFFIX(print,name),ln)(type n) \
{ \
  PRINTLN_BODY(SUFFIX(print,name)(n)) \
}

#define DEFINE_PRINT_INT(name, type) \
  DEFINE_PRINT_UINT(SUFFIX(u, name), unsigned type) \
\
int SUFFIX(print,name)(type n) \
{ int written = 0; \
  int tmp; \
  if (n < 0) { \
    n = -(n + 1) + 1; \
    written = printchar('-'); \
    if (written < 0) \
      return written; \
  } \
  tmp = SUFFIX(printu,name)(n); \
  if (tmp < 0) \
    return tmp; \
  else \
    written += tmp; \
  return written; \
} \
int SUFFIX(SUFFIX(print,name),ln)(type n) \
{ \
  PRINTLN_BODY(SUFFIX(print,name)(n)) \
}

DEFINE_PRINT_INT(int, int)
DEFINE_PRINT_INT(llong, long long)

int printhex(unsigned n)
{
  return printuint_base(n, 16);
}

int printhexln(unsigned n)
{
  PRINTLN_BODY(printhex(n))
}

int printllonghex(unsigned long long n)
{
  return printullong_base(n, 16);
}

int printllonghexln(unsigned long long n)
{
  PRINTLN_BODY(printllonghex(n))
}

int printbin(unsigned n)
{
  return printuint_base(n, 2);
}

int printbinln(unsigned n)
{
  PRINTLN_BODY(printbin(n))
}

int printstr(const char *s)
{
  int len = strlen(s);
  return _write(FD_STDOUT, s, len);
}

int printstrln(const char *s)
{
  PRINTLN_BODY(printstr(s))
}
