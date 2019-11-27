/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <pmux/bus/channel.h++>
#include <pmux/client/tty.h++>
#include <pmux/client/session.h++>
#include <pmux/renderer/xterm.h++>
#include <pmux/renderer/awesome.h++>
#include <cstring>
#include <iostream>

static void show_help_text(std::string name)
{
    std::cerr
        << name << ": [command] [command]...\n"
        << "    Runs the given list of commands.\n"
        << "    Commands include:\n"
        << "        new-tty:        Creates a new terminal\n"
        << "        new-session:    Creates a new session\n"
        << "        start-awesome:  Launches the awesome window manager\n"
        << std::endl;
}

int main(int argc, const char **argv)
{
    const char *help_argv[] = {argv[0], "--help", nullptr};
    int ret = 0;
    if (argc == 1) {
        argc = 2;
        argv = help_argv;
        ret = 1;
    }

    for (int i = 1; i < argc; ++i) {
        auto scn = [&](const char *s) {
            return strcmp(argv[i], s) == 0;
        };

        if (scn("new-tty")) {
            auto session = pmux::client::session::current();
            auto tty = session->new_tty();
        } else if (scn("new-session")) {
            auto old_session = pmux::client::session::current();
            auto new_session = old_session->new_empty_session();
            pmux::client::session::current(new_session);
        } else if (scn("start-awesome")) {
            auto awesome = pmux::renderer::awesome();
        } else if (scn("--help")) {
            show_help_text(argv[0]);
        } else {
            std::cerr << "Unknown argument " << std::string(argv[i]) << "\n";
            abort();
        }
    }

    return ret;
}
