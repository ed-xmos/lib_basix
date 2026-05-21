// Copyright 2025 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.
#include <platform.h>
#include "basix.h"

void f()
{
    basix_print_meaning_of_life();
    int x = basix_get_meaning_of_life();
}

int main()
{
    par
    {
        f();
    }
}
