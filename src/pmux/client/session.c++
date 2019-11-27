/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include "session.h++"
#include <cstdlib>
using namespace pmux::client;

std::shared_ptr<session> session::__current = nullptr;

std::shared_ptr<tty> session::new_tty(void)
{
    abort();
}

std::shared_ptr<session> session::new_empty_session(void)
{
    abort();
}
