/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:59:00 by oaydemir          #+#    #+#             */
/*   Updated: 2023/06/06 05:59:16 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <csignal>
#include "IRCServer/IRCServer.hpp"
#include <string>
#include <sstream>

IRCServer* g_ircServer;

void sigint_handler(int signum)
{
    if (g_ircServer)
    {
		// call the destructor of IRCServer
        g_ircServer->~IRCServer();
        g_ircServer = NULL;
    }
    // system("say -v Lekha Safe travels, dear user! Until our digital paths cross again. Keep exploring.");

    std::exit(signum);
}

bool isNumber(const std::string& s) {
    std::stringstream ss(s);
    double d;
    return !((ss >> d).fail());
}

int main(int argc, char *argv[])
{
    // Set up the SIGINT signal handler
    std::signal(SIGINT, sigint_handler);
    std::signal(SIGTSTP, sigint_handler);
    if (argc != 3 || !isNumber(argv[1]))
    {
        std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
        return 1;
    }
    try
    {
        int port = std::atoi(argv[1]);
        std::string password = argv[2];
        IRCServer ircServer(port, password);
        g_ircServer = &ircServer;
        ircServer.run();
        g_ircServer->~IRCServer();
        g_ircServer = NULL;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
