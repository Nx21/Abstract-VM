/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:16:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/26 11:36:34 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define  STACK_HPP

#include <stack>
#include "../operand/IOperand.hpp"

class Stack 
{
    private:
        std::stack<IOperand> _stack;
    public:
        void push(IOperand const &val);
        void pop();
        void assert(IOperand const &val);
        void add();
        void sub();
        void mul();
        void div();
        void print() const;
};
#endif