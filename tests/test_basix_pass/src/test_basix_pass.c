// Copyright 2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#include <platform.h>
#include <assert.h>
#include <print.h>
#include "basix.h"

int main()
{
    int mol = basix_get_meaning_of_life();

    assert(mol == BASIX_MEANING_OF_LIFE);

    printstr("PASS");
    return 0;
}
