/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operandfactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:25:54 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/27 12:39:52 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/common.hpp"

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const & value) const{
    auto it = this->method_map.find(type);
    if(it == method_map.end())
        throw "error type";
   return  (this->*it->second)(value);
}

IOperand const *OperandFactory::createInt8( std::string const & value ) const {
    return new Int8(value);
}

IOperand const *OperandFactory::createInt16( std::string const & value ) const {
    return new Int16(value);
}

IOperand const *OperandFactory::createInt32( std::string const & value ) const {
    return new Int32(value);
}

IOperand const *OperandFactory::createFloat( std::string const & value ) const {
    return new Float(value);
}

IOperand const *OperandFactory::createDouble( std::string const & value ) const {
    return new Double(value);
}