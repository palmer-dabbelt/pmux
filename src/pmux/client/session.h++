/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PMUX__CLIENT__SESSION_HXX
#define PMUX__CLIENT__SESSION_HXX

namespace pmux {
    namespace client {
        class session;
    }
}

#include "tty.h++"
#include <memory>

namespace pmux {
    namespace client {
        /* A user's session, which is really a workspace.  Once within pmux
         * there is always a current session, which can be implicitly
         * referenced by various other commands. */
        class session {
        private:
            static std::shared_ptr<session> __current;

        public:
            /* Creates a new TTY, attached to this session. */
            std::shared_ptr<tty> new_tty(void);

            /* Creates a new session, which doesn't have any children. */
            std::shared_ptr<session> new_empty_session(void);

            /* The current session is automatically managed by the rest of the
             * system. */
            static const auto& current(void) { return __current; }
            static void current(const decltype(__current)& set) { __current = set; }
        };
    }
}

#endif
