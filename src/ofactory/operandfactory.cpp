/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operandfactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:25:54 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/10 15:34:40 by nasreddineh      ###   ########.fr       */
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

IOperand const *SOperandFactory::StoO(const std::string &str)
{
    size_t pos = str.find('(');
    if(pos == str.npos && str[str.size() - 1] != ')')
        throw "invalid syntax " + str + "\n";
    std::string key = str.substr(0, pos);
    trim(key, " \n\t()");
    std::string value = str.substr(pos);
    trim(value, " \n\t()");
    return OperandFactory().createOperand(StoEO(key), value);
}

eOperandType StoEO::operator[](std::string const &str)
{
    auto it = this->_val.find(str);
    if(this->_val.find(str) == this->_val.end())
        throw "invalid key " + str + "\n";
    return it->second;
};

eOperandType StoEO::operator[](std::type_index  type)
{
    auto it = this->_valt.find(type);
    if(this->_valt.find(type) == this->_valt.end())
        throw "invalid key \n";
    return it->second;
};