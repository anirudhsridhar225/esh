//
// Created by anirudh on 12/23/25.
//

#include "include/shell.h"

#include <boost/asio.hpp>
#include <boost/asio/ip/host_name.hpp>
#include <boost/system/detail/error_code.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

std::string get_prompt() {
    boost::system::error_code ec;
    std::string hostname = boost::asio::ip::host_name(ec);

    if (ec) {
        std::cerr << "Error: " << ec.message() << "\n";
        return "";
    }

    hostname = hostname + " ~> ";
    return hostname;
}

std::vector<std::string> split(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string tok;

    while (iss >> tok) {
        tokens.push_back(tok);
    }

    return tokens;
}

void builtin_cd(const std::vector<std::string>& args) {
    const char* home = std::getenv("HOME");
    std::string path;

    if (args.size() == 1 || args[1] == "~") {
        if (!home) {
            std::cerr << "cd: HOME not set\n";
            return;
        }
        path = home;
    } else if (args[1].rfind("~/", 0) == 0) {
        if (!home) {
            std::cerr << "cd: HOME not set\n";
            return;
        }
        path = std::string(home) + args[1].substr(1);
    } else {
        path = args[1];
    }

    if (chdir(path.c_str()) != 0) {
        perror("cd");
    }
}

int handle_input(std::string& cmd) {
    std::getline(std::cin, cmd);
    std::cout << "command: " << cmd << "\n";
    if (cmd.empty())
        return 1;

    auto args = split(cmd);
    const std::string& command = args[0];

    if (command == "exit") {
        return -1;
    }

    if (command == "cd") {
        builtin_cd(args);
        return 0;
    }

    if (!cmd.empty()) {
        std::system(cmd.c_str());
    }

    return 1;
}
