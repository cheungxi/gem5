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

#ifndef __ARCH_LOONGARCH_TLB_HH__
#define __ARCH_LOONGARCH_TLB_HH__

#include <vector>

#include "arch/generic/tlb.hh"
#include "base/statistics.hh"
#include "mem/request.hh"
#include "params/LoongArchTLB.hh"

namespace gem5
{

class ThreadContext;

namespace LoongArchISA
{

class TLB : public BaseTLB
{
  protected:
    int size;

  public:
    TLB(const LoongArchTLBParams &p) : BaseTLB(p), size(p.size)
    {
    }

    void
    demapPage(Addr vaddr, uint64_t asn) override
    {
    }

    Fault
    translateAtomic(const RequestPtr &req, ThreadContext *tc,
                    BaseMMU::Mode mode) override
    {
        // For SE mode, just pass through virtual addresses
        return NoFault;
    }

    void
    translateTiming(const RequestPtr &req, ThreadContext *tc,
                    BaseMMU::Translation *translation,
                    BaseMMU::Mode mode) override
    {
        translation->finish(translateAtomic(req, tc, mode), req,
                            tc, mode);
    }

    Fault
    finalizePhysical(const RequestPtr &req, ThreadContext *tc,
                     BaseMMU::Mode mode) const override
    {
        return NoFault;
    }

    void
    takeOverFrom(BaseTLB *otlb) override
    {
    }
};

} // namespace LoongArchISA
} // namespace gem5

#endif // __ARCH_LOONGARCH_TLB_HH__
