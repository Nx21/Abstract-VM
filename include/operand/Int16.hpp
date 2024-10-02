/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:25:13 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/02 09:54:12 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INT16_HPP
# define INT16_HPP

#include "../ofactory/operandfactory.hpp"
#include <cstdint>

class Int16 : public IOperand
{
    private:
        int16_t _val;
    public:
        Int16();
        Int16(std::string const &str);
        Int16(IOperand const &src);
        int getPrecision( void ) const ;
        eOperandType getType( void ) const ;
        IOperand const * operator+( IOperand const & rhs ) const ;
        IOperand const * operator-( IOperand const & rhs ) const ; 
        IOperand const * operator*( IOperand const & rhs ) const ;
        IOperand const * operator/( IOperand const & rhs ) const ;
        IOperand const * operator%( IOperand const & rhs ) const ; 
        bool operator==( IOperand const & rhs ) const;
        std::string const & toString( void ) const ; 
        ~Int16( void );
};

#endif