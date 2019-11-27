/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PMUX__BUS__CLOCK_HXX
#define PMUX__BUS__CLOCK_HXX

namespace pmux {
    namespace bus {
        /* A logical clock, which produces timestamps -- essentially it's the
         * bits of a Lamport clock that I can remember.  The general idea here
         * is that the clock produces timestamps that only ever increase, but
         * that may not be uniform. */
        class clock {
        public:
            /* The whole point of a logical clock is to produce timestamps,
             * which I'm treating as an opaque object to avoid users poking too
             * much into them. */
            class timestamp {
            };

        private:
        };
    }
}

#endif
