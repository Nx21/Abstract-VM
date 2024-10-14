/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operandfactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:25:54 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/14 13:53:13 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPRANDFACTORY_HPP
# define OPRANDFACTORY_HPP
#include "../operand/Operand.hpp"
#include <cstddef>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>


class OperandFactory{
    public:
        OperandFactory(){};
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
    private:
        typedef IOperand const * (OperandFactory::*method_function)(std::string const &) const;
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
        std::map<eOperandType, method_function > method_map = 
        {
            {INT8, &OperandFactory::createInt8},
            {INT16, &OperandFactory::createInt16},
            {INT32, &OperandFactory::createInt32},
            {FLOAT, &OperandFactory::createFloat},
            {DOUBLE, &OperandFactory::createDouble}
        };
};

class StoEO
{
    public:
        eOperandType operator[](std::type_index  type);
        eOperandType operator[](std::string const &str);
        StoEO(){};
    private:
        std::map<std::type_index,eOperandType> _valt = 
        {
            {typeid(int8_t), INT8},
            {typeid(int16_t), INT16},
            {typeid(int32_t), INT32},
            {typeid(float_t), FLOAT},
            {typeid(double_t), DOUBLE}

        };
        std::map<std::string,eOperandType> _val = 
        {
            {"int8", INT8},
            {"int16", INT16},
            {"int32", INT32},
            {"float", FLOAT},
            {"double", DOUBLE}
        };
};

class SOperandFactory{
    public:
        SOperandFactory(){};
        static OperandFactory const OperandFactory()
        {
            static class OperandFactory _OperandFactory;
            return _OperandFactory;
        };
        static eOperandType StoEO(std::string const &str){
            static class StoEO _StoEO;
            return _StoEO[str];
        };
        static eOperandType StoEO(std::type_index const &str){
            static class StoEO _StoEO;
            return _StoEO[str];
        };;
        static IOperand const * StoO(std::string const &str);
};

#endif