/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:25:13 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/26 09:14:18 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INT32_HPP
# define INT32_HPP

#include "../ofactory/operandfactory.hpp"
#include <cstdint>

class Int32 : public IOperand
{
    private:
        int32_t _val;
    public:
        Int32();
        Int32(std::string const &str);
        Int32(IOperand const &src);
        int getPrecision( void ) const ;
        eOperandType getType( void ) const ;
        IOperand const * operator+( IOperand const & rhs ) const ;
        IOperand const * operator-( IOperand const & rhs ) const ; 
        IOperand const * operator*( IOperand const & rhs ) const ;
        IOperand const * operator/( IOperand const & rhs ) const ;
        IOperand const * operator%( IOperand const & rhs ) const ;
        std::string const & toString( void ) const ; 
        ~Int32( void );
};

#endif