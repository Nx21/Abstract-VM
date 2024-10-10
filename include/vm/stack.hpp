/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/10 10:13:04 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define  STACK_HPP

#include "../utils/MutantStack.hpp"
#include "../operand/Operand.hpp"

class Stack 
{
    private:
        std::deque<const IOperand*> _stack;
    public:
        void push(std::string const &str);
        void pop();
        void dump() const;
        void Assert(std::string const &str);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void print() const;
};
#endif