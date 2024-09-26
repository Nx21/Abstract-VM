/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:25:13 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/25 22:03:33 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INT8_HPP
# define INT8_HPP

#include "../ofactory/operandfactory.hpp"
#include <cstdint>

class Int8 : public IOperand
{
    private:
        int8_t _val;
    public:
        Int8();
        Int8(std::string const &str);
        Int8(IOperand const &src);
        int getPrecision( void ) const ;
        eOperandType getType( void ) const ;
        IOperand const * operator+( IOperand const & rhs ) const ;
        IOperand const * operator-( IOperand const & rhs ) const ; 
        IOperand const * operator*( IOperand const & rhs ) const ;
        IOperand const * operator/( IOperand const & rhs ) const ;
        IOperand const * operator%( IOperand const & rhs ) const ;
        std::string const & toString( void ) const ; 
        ~Int8( void );
};

#endif