/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:28:55 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/14 14:58:19 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.hpp"



void Stack::push(std::string const &str)
{
    IOperand const *val = SOperandFactory::StoO(str);
    this->_stack.push_front(val);
}

void Stack::pop()
{
    if(this->_stack.size())
        return this->_stack.pop_front();
    throw "Stack is empty\n";
}

void Stack::dump() const
{
    auto it = this->_stack.begin();
    while (it != this->_stack.end()) {
        std::cout << (*it)->toString() << "\r";
    }
    std::cout << std::endl;
}

void Stack::Assert(std::string const &str)
{
    auto val1 = SOperandFactory::StoO(str);
    auto &val2 = this->_stack.front();
    if(val1->getType() == val2->getType() && val1->toString() == val2->toString())
        throw val1->toString() + " not equal to " + val2->toString();
    delete val1;
}

void Stack::add()
{
    if (!this->_stack.size()) {
        throw "empty stack";
    }
    auto val1 = this->_stack.front();
    this->_stack.pop_front();
    auto val2 = this->_stack.front();
    this->_stack.pop_front();
    auto result = *val1 + *val2;
    this->_stack.push_front(result);
}

void Stack::sub()
{
    if (!this->_stack.size()) {
        throw "empty stack";
    }
    auto &val1 = this->_stack.front();
    this->_stack.pop_front();
    auto &val2 = this->_stack.front();
    this->_stack.pop_front();
    auto result = *val1 - *val2;
    this->_stack.push_front(result);
}

void Stack::mul()
{
    if (!this->_stack.size()) {
        throw "empty stack";
    }
    auto &val1 = this->_stack.front();
    this->_stack.pop_front();
    auto &val2 = this->_stack.front();
    this->_stack.pop_front();
    auto result = *val1 * *val2;
    this->_stack.push_front(result);
}

void Stack::div()
{
    if (!this->_stack.size()) {
        throw "empty stack";
    }
    auto &val1 = this->_stack.front();
    this->_stack.pop_front();
    auto &val2 = this->_stack.front();
    this->_stack.pop_front();
    auto result = *val1 / *val2;
    this->_stack.push_front(result);
}

void Stack::mod()
{
    if (!this->_stack.size()) {
        throw "empty stack";
    }
    auto &val1 = this->_stack.front();
    this->_stack.pop_front();
    auto &val2 = this->_stack.front();
    this->_stack.pop_front();
    auto result = *val1 % *val2;
    this->_stack.push_front(result);
}

void Stack::print() const
{
    if (this->_stack.front()->getType() != INT8)
        throw "invalid type";
    char res = stoi(this->_stack.front()->toString());
    std::cout << res << std::endl;
}