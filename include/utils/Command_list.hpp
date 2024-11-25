/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command_list.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasr <nasr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:11:00 by nasr              #+#    #+#             */
/*   Updated: 2024/11/19 19:12:32 by nasr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LIST
#define COMMAND_LIST
#include <iostream>

typedef struct s_commandList
{
    size_t line_number;
    std::string command;
    std::string value;
    std::string type;
} t_commandList;

#endif