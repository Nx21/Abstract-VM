/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:25:13 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/23 18:59:30 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Float_HPP
# define Float_HPP

#include "IOperand.hpp"

class Float : public IOperand
{
    private:
        float _val;
    public:
        Float();
        Float(std::string const &str);
        int getPrecision( void ) const ;
        eOperandType getType( void ) const ;
        IOperand const * operator+( IOperand const & rhs ) const ;
        IOperand const * operator-( IOperand const & rhs ) const ; 
        IOperand const * operator*( IOperand const & rhs ) const ;
        IOperand const * operator/( IOperand const & rhs ) const ;
        IOperand const * operator%( IOperand const & rhs ) const ;
        std::string const & toString( void ) const ; 
        ~Float( void );
};

#endif