// Copyright 2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#ifndef _BASIX_H_
#define _BASIX_H_

#ifdef __basix_conf_h_exists__
#include "basix_conf.h"
#endif

#ifndef BASIX_MEANING_OF_LIFE
#define BASIX_MEANING_OF_LIFE (42)
#endif

/** Example function
 * \brief This function returns the meaning of life to the console.
 * \return The meaning of life as an integer.
 */
int basix_get_meaning_of_life();

/** Exammple function.
 *
 * \brief This function prints the meaning of life to the console.
 *
 */
void basix_print_meaning_of_life();

#endif // _BASIX_H_
