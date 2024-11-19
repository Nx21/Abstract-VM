/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:43:35 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/14 15:43:44 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/common.hpp"
int main(int ac, char**av)
{
    if(ac > 1)
    {
        std::string s(av[1]);
        FileParsing f(s);
    }
    else
    {

    }
}