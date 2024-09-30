/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/30 10:00:14 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define  STACK_HPP

#include "../utils/MutantStack.hpp"
#include "../operand/IOperand.hpp"

class Stack 
{
    private:
        MutantStack<IOperand> _stack;
    public:
        void push(std::string const &str);
        void dump();
        void pop();
        void assert(std::string const &str);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void print() const;
};
#endif