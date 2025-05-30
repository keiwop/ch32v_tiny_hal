// Copyright (C): 2025 - keiwop
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef     __MACRO__
#define     __MACRO__


#define     diff(a, b)      (a > b ? a - b : b - a)

#define     nop()           __asm__ __volatile__ ("nop")
#define     halt()          while(1){ nop(); }


#endif // __MACRO__
