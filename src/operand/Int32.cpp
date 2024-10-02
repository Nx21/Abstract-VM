/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:54:20 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/24 10:47:40 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operand/Int32.hpp"
#include <cstdint>
#include <limits>
#include <string>

Int32::Int32() : _val(0)
{}

Int32::~Int32()
{}

Int32::Int32(std::string const &str){
    int64_t tmp = std::stoll(str);
    if(tmp > std::numeric_limits<int32_t>::max() || 
        tmp < std::numeric_limits<int32_t>::min())
        throw "out of range";  
    this->_val = tmp;
}

int Int32::getPrecision() const { 
    return 0;
}

eOperandType Int32::getType( void ) const {
    return INT32;
}

IOperand const * Int32::operator+( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) + static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) + static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator*( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) * static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) * static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator-( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) - static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) - static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator/( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) / static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) / static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

IOperand const * Int32::operator%( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) % static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    throw "Wrong type(s)";
}

bool Int32::operator==( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        bool result = (static_cast<int64_t>(this->_val) == static_cast<int64_t>(std::stoll(rhs.toString())));
        return result;
    }
    bool result = (static_cast<double>(this->_val) == static_cast<double>(std::stod(rhs.toString())));
    return result;
}