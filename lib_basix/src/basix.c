// Copyright 2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#include "basix.h"
#include <stdio.h>

int basix_get_meaning_of_life()
{
    return BASIX_MEANING_OF_LIFE;
}

void basix_print_meaning_of_life()
{
    printf("The meaning of life, the universe, and everything is %d\n", BASIX_MEANING_OF_LIFE);
}
