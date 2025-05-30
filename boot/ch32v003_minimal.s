/* Copyright (C): 2025 - keiwop */
/* SPDX-License-Identifier: GPL-3.0-or-later */

.section .init

_sp:        /* Who needs a stack pointer anyway? */

_main:      /* Start main loop from C*/   
    call main
