/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:19 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/09 17:29:05 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define  OPERAND_HPP

#include <cstdint>
#include <iostream>
#include <string>

enum eOperandType
{
    INT8 = 1,
    INT16 = 2,
    INT32 = 4,
    FLOAT = 8,
    DOUBLE = 16
};


class IOperand {
    public:
    virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
    virtual eOperandType getType( void ) const = 0; // Type of the instance
    virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
    virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
    virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
    virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
    virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
    virtual bool operator==( IOperand const & rhs ) const = 0; // equal
    virtual std::string const & toString( void ) const = 0; // String representation of the instance
    virtual ~IOperand( void ) {}
};

template<typename T>
class Operand :public IOperand 
{
    private:
        T _val;
        eOperandType _type;
        std::string _valstr;
    public:
        Operand(std::string const &str);
        Operand(T const &val);
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
        ~Operand( void );
};


using Int8 = Operand<int8_t>;
using Int16 = Operand<int16_t>;
using Int32 = Operand<int32_t>;
using Float = Operand<float>;
using Double = Operand<double>;

#endif
