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

#ifndef OPERAND_HPP
#define  OPERAND_HPP
#include "IOperand.hpp"
#include <cstdint>
#include <string>



template<class T>
class Operand :public IOperand 
{
    private:
        T _val;
        eOperandType _type;
        std::string _valstr;
    public:
        Operand(std::string const &str);
        Operand();
        int getPrecision( void ) const ;
        eOperandType getType( void ) const ;
        IOperand const * operator+( IOperand const & rhs ) const ;
        IOperand const * operator-( IOperand const & rhs ) const ; 
        IOperand const * operator*( IOperand const & rhs ) const ;
        IOperand const * operator/( IOperand const & rhs ) const ;
        IOperand const * operator%( IOperand const & rhs ) const ; 
        bool operator==( IOperand const & rhs ) const;
        std::string const & toString( void ) const ;
        ~Operand( void ){};
};


using Int8 = Operand<int8_t>;
using Int16 = Operand<int16_t>;
using Int32 = Operand<int32_t>;
using Float = Operand<float>;
using Double = Operand<double>;

#endif