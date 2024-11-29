/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasr <nasr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/11/29 21:59:23 by nasr             ###   ########.fr       */
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
        typedef void (Command::*method_function)(t_commandList const &);
        void push(t_commandList const &list);
        void pop(t_commandList const &list);
        void dump(t_commandList const &list);
        void Assert(t_commandList const &list);
        void add(t_commandList const &list);
        void sub(t_commandList const &list);
        void mul(t_commandList const &list);
        void div(t_commandList const &list);
        void mod(t_commandList const &list);
        void print(t_commandList const &list);
        void exit(t_commandList const &list);
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
            {"dump", &Command::dump},
            {"print", &Command::print},
            {"exit", &Command::exit}
        };
    public:
        void exec(t_commandList const &list);
        void command(std::string const &str);
        void command();

};
#endif