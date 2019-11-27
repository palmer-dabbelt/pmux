/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#ifndef PMUX__BUS__CHANNEL_HXX
#define PMUX__BUS__CHANNEL_HXX

#include "clock.h++"

namespace pmux {
    namespace bus {
        /* A single logical bus channel.  Channels go in one direction, but can
         * have an arbitrary number of producers and consumers.  Behind the s*/
        class channel {
        public:
            /* Channels are represented by a unique ID, which is global. */
            class uid {
            };

            /* Users can take out two reservations on a channel: one for
             * reading and one for writing.  Taking out a reservation guarantees
             * that this client participates in the ordering scheme.  These are
             * capable of blocking each other, so be careful if you take out
             * both at the same time. */
            class pub {
            };

            class sub {
            };

            /* Channels consist of an ordered set of messages, which are
             * treated as a simple list of bytes with a timestamp attached to
             * it in case someone wants to order messages. */
            class message {
            };

        private:
            const uid _name;

        public:
            channel(const uid& name)
            : _name(name)
            {}
        };
    }
}

#endif
