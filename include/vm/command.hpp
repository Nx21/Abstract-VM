/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/09 17:54:28 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define  COMMAND_HPP

#include "./stack.hpp"
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
        void assert(std::string const &str);
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
            {"assert", &Command::assert},
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

};
#endif