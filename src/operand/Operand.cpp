/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:54:20 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/02 13:37:00 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.hpp"
#include <cstdint>
#include <limits>
#include <string>

template<typename T>
Operand<T>::Operand() : _val(0)
{}

template<typename T>
Operand<T>::~Operand()
{}

template<typename T>
Operand<T>::Operand(std::string const &str){
    std::ostringstream oss(str);
    oss << this->_val;
    this->_type = SOperandFactory::StoEO[typeid(T)];
    this->_valstr = toString(this->_val);
}

template<typename T>
int Operand<T>::getPrecision() const { 
    return 0;
}

template<typename T>
eOperandType Operand<T>::getType( void ) const {
    return this->_type;
}

template<typename T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) + static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) + static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

template<typename T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) * static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) * static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

template<typename T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) - static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) - static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::OperandFactory.createOperand(type, std::to_string(result));
}

template<typename T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const{
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

template<typename T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const{
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

template<typename T>
bool Operand<T>::operator==( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        bool result = (static_cast<int64_t>(this->_val) == static_cast<int64_t>(std::stoll(rhs.toString())));
        return result;
    }
    bool result = (static_cast<double>(this->_val) == static_cast<double>(std::stod(rhs.toString())));
    return result;
}