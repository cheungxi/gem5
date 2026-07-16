/*
 * Copyright (c) 2024 Loongson Technology Corporation Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ARCH_LOONGARCH_REGS_INT_HH__
#define __ARCH_LOONGARCH_REGS_INT_HH__

#include "cpu/reg_class.hh"

namespace gem5
{

namespace LoongArchISA
{

// Number of general purpose integer registers (r0-r31)
const int NumIntRegs = 32;

// Semantic register indices
const int ReturnValueReg = 4;  // $r4
const int ArgumentReg[] = {4, 5, 6, 7, 8, 9, 10, 11};  // $r4-$r11
const int NumArgumentRegs = 8;
const int StackPointerReg = 3;  // $r3
const int GlobalPointerReg = 2;  // $r2
const int ThreadPointerReg = 2;  // $r2
const int FramePointerReg = 22;  // $r22
const int ReturnAddressReg = 1;  // $r1
const int ZeroReg = 0;  // $r0

} // namespace LoongArchISA
} // namespace gem5

#endif // __ARCH_LOONGARCH_REGS_INT_HH__
