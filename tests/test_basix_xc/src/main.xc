// Copyright 2026 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#include <basix.h>

int main(void)
{
    unsigned before = basix_time_now();
    basix_delay_ticks(10);

    if ((basix_time_now() - before) < 10)
        basix_trap();

    printstr("XC PASS\n");
    return 0;
}
