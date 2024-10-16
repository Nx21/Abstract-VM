/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:57:56 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/16 14:09:11 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSING_HPP
#define  FILE_PARSING_HPP
#include "../vm/command.hpp"
#include <fstream>
#include <string>

class FileParising{
    private:
        Command _command;
        std::ifstream _file;
    public:
        FileParising(std::string const &filename);
};

#endif