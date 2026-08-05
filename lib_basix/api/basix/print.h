// Copyright 2026 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.
#ifndef _print_h_
#define _print_h_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \file print.h
 * \brief XC printing routines
 *
 * The print.h library provides support for formatted output.
 */

/**
 * Prints a character.
 * \param value The character to print.
 * \return The number of characters printed, or -1 on error.  */
int printchar(char value);

/**
 * Prints a character followed by a new line.
 * \param value The character to print.
 * \return The number of characters printed, or -1 on error.  */
int printcharln(char value);

/**
 * Prints a value as a signed decimal.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printint(int value);

/**
 * Prints a value as a signed decimal followed by a newline.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printintln(int value);

/**
 * Prints a value as a unsigned decimal.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printuint(unsigned value);

/**
 * Prints a value as a unsigned decimal followed by a newline.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printuintln(unsigned value);

/**
 * Prints a long long value as a signed decimal.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printllong(long long value);

/**
 * Prints a long long value as a signed decimal followed by a newline.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printllongln(long long value);

/**
 * Prints a long long value as a unsigned decimal.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printullong(unsigned long long value);

/**
 * Prints a long long value as a unsigned decimal followed by a newline.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printullongln(unsigned long long value);

/**
 * Prints a value as a unsigned hexadecimal. The upper-case letters
 * \p ABCDEF are used for the conversion.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printhex(unsigned value);

/**
 * Prints a value as a unsigned hexadecimal followed by a newline.
 * The upper-case letters \p ABCDEF are used for the conversion.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printhexln(unsigned value);

/**
 * Prints a long long value as a unsigned hexadecimal. The upper-case letters
 * \p ABCDEF are used for the conversion.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printllonghex(unsigned long long value);

/**
 * Prints a long long value as a unsigned hexadecimal followed by a newline.
 * The upper-case letters \p ABCDEF are used for the conversion.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printllonghexln(unsigned long long value);

/**
 * Prints a value as an unsigned binary number.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printbin(unsigned value);

/**
 * Prints a value as an unsigned binary number followed by a newline.
 * \param value The value to print.
 * \return The number of characters printed, or -1 on error.  */
int printbinln(unsigned value);

/**
 * Prints a null terminated string.
 * \param s The string to print.
 * \return The number of characters printed, or -1 on error.  */
#if defined(__XC__)
int printstr(const char (& alias s)[]);
#else
int printstr(const char *s);
#endif /* defined(__XC__) */

/**
 * Prints a null terminated string followed by a newline.
 * \param s The string to print.
 * \return The number of characters printed, or -1 on error.  */
#if defined(__XC__)
int printstrln(const char (& alias s)[]);
#else
int printstrln(const char *s);
#endif /* defined(__XC__) */

#ifdef __cplusplus
} //extern "C"
#endif

#endif // _print_h_
