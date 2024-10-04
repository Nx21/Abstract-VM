/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:07:19 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/04 10:53:29 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define  IOPERAND_HPP
#include <iostream>

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


#endif
