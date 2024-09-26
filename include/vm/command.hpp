/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/26 11:33:25 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define  COMMAND_HPP

#include "./stack.hpp"

class command 
{
    private:
        Stack _stack;
    public:
        void push(std::string const &str);
        void pop(std::string const &str);
        void assert(std::string const &str);
        void add(std::string const &str);
        void sub(std::string const &str);
        void mul(std::string const &str);
        void div(std::string const &str);
        void mod(std::string const &str);
        void print(std::string const &str);
        void exit(std::string const &str);

};

#endif