/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PMUX__CLIENT__TTY_HXX
#define PMUX__CLIENT__TTY_HXX

namespace pmux {
    namespace client {
        class tty;
    }
}

#include "session.h++"
#include <memory>

namespace pmux {
    namespace client {
        /* A TTY is essentially just a two way communication stream, but it's
         * one that's really optimized for low latency single character
         * messages. */
        class tty {
        public:
            /* Creates a new TTY, which is part of a session */
            tty(const std::shared_ptr<session>& session);
        };
    }
}

#endif
