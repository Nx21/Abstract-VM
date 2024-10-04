/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:54:20 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/02 13:37:00 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operand/Int8.hpp"
#include <cstdint>
#include <limits>
#include <string>

Int8::Int8() : _val(0)
{}

Int8::~Int8()
{}

Int8::Int8(std::string const &str){
    int64_t tmp = std::stoll(str);
    if(tmp > std::numeric_limits<int8_t>::max() || 
        tmp < std::numeric_limits<int8_t>::min())
        throw "out of range";  
    this->_val = tmp;
}

int Int8::getPrecision() const { 
    return 0;
}

eOperandType Int8::getType( void ) const {
    return INT8;
}

IOperand const * Int8::operator+( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) + static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) + static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Int8::operator*( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) * static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) * static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Int8::operator-( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) - static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) - static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}
//update other types 
IOperand const * Int8::operator/( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        auto dim = static_cast<int64_t>(std::stoll(rhs.toString()));
        if(dim == 0)
            throw "division by zero";
        int64_t result = static_cast<int64_t>(this->_val) / dim;
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
     auto dim = static_cast<double>(std::stod(rhs.toString()));
        if(dim == 0)
            throw "division by zero";
    double result = static_cast<double>(this->_val) / dim;
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Int8::operator%( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        auto dim = static_cast<int64_t>(std::stoll(rhs.toString()));
        if(dim == 0)
            throw "integer modulo by zero";
        int64_t result = static_cast<int64_t>(this->_val) % static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    throw "Wrong type(s)";
}

bool Int8::operator==( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        bool result = (static_cast<int64_t>(this->_val) == static_cast<int64_t>(std::stoll(rhs.toString())));
        return result;
    }
    bool result = (static_cast<double>(this->_val) == static_cast<double>(std::stod(rhs.toString())));
    return result;
}