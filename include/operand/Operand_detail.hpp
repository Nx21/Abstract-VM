/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand_detail.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasr <nasr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:54:09 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/11/29 22:24:43 by nasr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_DETAIL_HPP
#define  OPERAND_DETAIL_HPP

#include "../../include/ofactory/operandfactory.hpp"
#include <sstream>
template<class T>
Operand<T>::Operand(std::string const &str): _val(0), _valstr(""){
    std::stringstream oss(str);
    // double tmp;
    oss >> this->_val;
    // this->_val = tmp;
    std::cout << std::type_name<std::decltype(this->_val)> << " Operand: " << str << std::endl;
    this->_type = SOperandFactory::StoEO(typeid(T));
    std::cout  << " Operand: " << this->_type << std::endl;
    this->_valstr = std::to_string(this->_val);
}
template<class T>
int Operand<T>::getPrecision() const { 
    return sizeof(T);
}

template<class T>
eOperandType Operand<T>::getType( void ) const {
    return this->_type;
}

template<class T>
IOperand const *Operand<T>::operator+( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) + static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) + static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
}

template<class T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) * static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) * static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
}

template<class T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        int64_t result = static_cast<int64_t>(this->_val) - static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
    }
    double result = static_cast<double>(this->_val) - static_cast<double>(std::stod(rhs.toString()));
    return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
}

template<class T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        auto dim = static_cast<int64_t>(std::stoll(rhs.toString()));
        if(dim == 0)
            throw "division by zero";
        int64_t result = static_cast<int64_t>(this->_val) / dim;
        return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
    }
     auto dim = static_cast<double>(std::stod(rhs.toString()));
        if(dim == 0)
            throw "division by zero";
    double result = static_cast<double>(this->_val) / dim;
    return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
}

template<class T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        auto dim = static_cast<int64_t>(std::stoll(rhs.toString()));
        if(dim == 0)
            throw "integer modulo by zero";
        int64_t result = static_cast<int64_t>(this->_val) % static_cast<int64_t>(std::stoll(rhs.toString()));
        return SOperandFactory::_OperandFactory().createOperand(type, std::to_string(result));
    }
    throw "Wrong type(s)";
}

template<class T>
bool Operand<T>::operator==( IOperand const & rhs ) const{
    eOperandType type = std::max(this->getType(), rhs.getType());
    if (type <= INT32) {
        bool result = (static_cast<int64_t>(this->_val) == static_cast<int64_t>(std::stoll(rhs.toString())));
        return result;
    }
    bool result = (static_cast<double>(this->_val) == static_cast<double>(std::stod(rhs.toString())));
    return result;
}

template<class T>
std::string const &Operand<T>::toString( void ) const 
{
    std::cerr << this->_val << ':';
    // this->_valstr = std::to_string(this->_val);
    return this->_valstr;
}
#endif