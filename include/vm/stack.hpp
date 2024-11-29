/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasr <nasr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/11/29 21:43:36 by nasr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define  STACK_HPP

#include <deque>
#include "../operand/Operand_detail.hpp"

class Stack 
{
    private:
        std::deque<const IOperand*> _stack;
    public:
        void push(std::string const &key, std::string const &value);
        void pop();
        void dump() const;
        void Assert(std::string const &key, std::string const &value);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void print() const;
};
#endif