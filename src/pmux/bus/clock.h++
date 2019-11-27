/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PMUX__BUS__CLOCK_HXX
#define PMUX__BUS__CLOCK_HXX

namespace pmux {
    namespace bus {
        /* A logical clock, which produces timestamps -- essentially it's the
         * bits of a Lamport clock that I can remember. */
        class clock {
        public:
            class timestamp {
            };

        private:
        };
    }
}

#endif
