//
// Created by anirudh on 12/23/25.
//

#include <boost/asio.hpp>
#include <boost/asio/ip/host_name.hpp>
#include <boost/system/detail/error_code.hpp>
#include <cstdlib>
#include <iostream>

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

int handle_input(std::string cmd) {
    std::getline(std::cin, cmd);
    std::cout << "command: " << cmd << "\n";

    if (cmd == "exit") {
        return -1;
    }

    if (!cmd.empty()) {
        std::system(cmd.c_str());
    }

    return 1;
}

int main() {
    std::string cmd;
    boost::system::error_code ec;
    std::string hostname = get_prompt();

    if (ec) {
        std::cerr << "Error: " << ec.message() << "\n";
        return 1;
    }

    while (true) {
        std::cout << hostname;
        int result = handle_input(cmd);

        if (result == -1)
            break;
    }

    return 0;
}
