/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:54:20 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/02 09:55:55 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.hpp"
#include <cstdint>
#include <limits>
#include <string>

Double::Double() : _val(0)
{}

Double::~Double()
{}

Double::Double(std::string const &str){
    double tmp = std::stoll(str);
    if(tmp > std::numeric_limits<double>::max() || 
        tmp < std::numeric_limits<double>::min())
        throw "out of range";
    this->_val = tmp;
    
}

int Double::getPrecision() const { 
    return 0;
}

eOperandType Double::getType( void ) const {
    return DOUBLE;
}

IOperand const * Double::operator+( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) + static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) + static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Double::operator*( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) * static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) * static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Double::operator-( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) - static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) - static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Double::operator/( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) / static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) / static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Double::operator%( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) % static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    throw "Wrong type(s)";
}

bool Double::operator==( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        bool result = (static_cast<int64_t>(this->_val) == static_cast<int64_t>(std::stoll(rhs.toString())));
        return result;
    }
    bool result = (static_cast<double>(this->_val) == static_cast<double>(std::stod(rhs.toString())));
    return result;
}