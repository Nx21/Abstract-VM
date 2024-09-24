/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operandfactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:25:54 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/24 10:10:35 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPRANDFACTORY_HPP
# define OPRANDFACTORY_HPP
#include "../operand/IOperand.hpp"
#include <map>

class OperandFactory{
    public:
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

class SOperandFactory{
    public:
        static OperandFactory OperandFactory;
};

#endif