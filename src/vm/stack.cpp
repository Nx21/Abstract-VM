/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:28:55 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/02 10:03:50 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.hpp"
#include <cassert>


void Stack::push(std::string const &str)
{
    IOperand const *val = SOperandFactory::StoO(str);
    this->_stack.push(*val);
}

void Stack::pop()
{
    if(this->_stack.size())
        return this->_stack.pop();
    throw "Stack is empty\n";
}

void Stack::dump() const
{
    auto it = this->_stack.begin();
    while (it != this->_stack.end()) {
        std::cout << it->toString() << "\r";
    }
    std::cout << std::endl;
}

void Stack::Assert(std::string const &str)
{
    auto val1 = SOperandFactory::StoO(str);
    auto &val2 = this->_stack.top();
    if(!((*val1) == val2))
        throw val1->toString() + " not equal to " + val2.toString();
    delete val1;
}

