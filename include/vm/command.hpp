/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasr <nasr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/11/19 19:16:45 by nasr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define  COMMAND_HPP

#include "./stack.hpp"
#include "../utils/Command_list.hpp"
#include <map>
#include <string>

class Command 
{
    private:
        Stack _stack;
        typedef void (Command::*method_function)(std::string const &);
        void push(std::string const &str);
        void pop(std::string const &str);
        void dump(std::string const &str);
        void Assert(std::string const &str);
        void add(std::string const &str);
        void sub(std::string const &str);
        void mul(std::string const &str);
        void div(std::string const &str);
        void mod(std::string const &str);
        void print(std::string const &str);
        void exit(std::string const &str);
        std::map<std::string, method_function > method_map = 
        {
            {"push", &Command::push},
            {"pop", &Command::pop},
            {"assert", &Command::Assert},
            {"add", &Command::add},
            {"sub", &Command::sub},
            {"mul", &Command::mul},
            {"div", &Command::div},
            {"mod", &Command::mod},
            {"print", &Command::print},
            {"exit", &Command::exit}
        };
    public:
        void command(std::string const &str);
        void command(t_commandList const &list);

};
#endif