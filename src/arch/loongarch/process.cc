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

#include "arch/loongarch/process.hh"

#include "arch/loongarch/isa.hh"
#include "arch/loongarch/regs/int.hh"
#include "base/loader/object_file.hh"
#include "cpu/thread_context.hh"
#include "debug/Loader.hh"
#include "mem/page_table.hh"
#include "sim/aux_vector.hh"
#include "sim/process.hh"
#include "sim/process_impl.hh"
#include "sim/syscall_return.hh"
#include "sim/system.hh"

namespace gem5
{

namespace LoongArchISA
{

Process::Process(const ProcessParams &params, loader::ObjectFile *objFile) :
    gem5::Process(params, objFile)
{
}

void
Process::initState()
{
    gem5::Process::initState();

    argsInit(PageBytes);
}

void
Process::argsInit(int pageSize)
{
    // Basic argument initialization
}

void
Process::setSyscallReturn(ThreadContext *tc, SyscallReturn return_value)
{
    if (return_value.successful()) {
        tc->setIntReg(ReturnValueReg, return_value.returnValue());
    } else {
        tc->setIntReg(ReturnValueReg, return_value.encodedValue());
    }
}

RegVal
Process::getSyscallArg(ThreadContext *tc, int &i)
{
    if (i < NumArgumentRegs)
        return tc->getIntReg(ArgumentReg[i++]);
    
    panic("LoongArch getSyscallArg: i >= NumArgumentRegs");
}

void
Process::setSyscallArg(ThreadContext *tc, int i, RegVal val)
{
    if (i < NumArgumentRegs)
        tc->setIntReg(ArgumentReg[i], val);
    else
        panic("LoongArch setSyscallArg: i >= NumArgumentRegs");
}

} // namespace LoongArchISA
} // namespace gem5
