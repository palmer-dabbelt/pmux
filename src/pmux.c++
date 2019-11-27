/* Copyright 2019 Palmer Dabbelt <palmerdabbelt@google.com> */
/* SPDX-License-Identifier: GPL-2.0+ OR Apache-2.0 OR BSD-3-Clause */

#include <pmux/bus/channel.h++>
#include <cstring>
#include <iostream>

static void show_help_text(std::string name)
{
    std::cerr << name << ": [command] [command]...\n";
    std::cerr << "    Runs the given list of commands\n";
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

        if (scn("--help")) {
            show_help_text(argv[0]);
        } else if (scn("new-terminal")) {
            std::cerr << "new-terminal unimplemented\n";
            abort();
        } else {
            std::cerr << "Unknown argument " << std::string(argv[i]) << "\n";
            abort();
        }
    }

    return ret;
}
