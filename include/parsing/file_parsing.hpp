/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:57:56 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/22 16:49:57 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSING_HPP
#define  FILE_PARSING_HPP
#include "../vm/command.hpp"
#include <cstddef>
#include <fstream>
#include <list>
#include <string>

typedef struct s_commandList
{
    size_t line_number;
    std::string command;
    std::string value;
    std::string type;
} t_commandList;


class FileParsing{
    private:
        Command _execCommand;
        std::ifstream _file;
        std::list<t_commandList> _listCommand;
        void checker();
        void parseLine(size_t nl, std::string &line);
        void exec();
        std::map<std::string, int > method_map = 
        {
            {"push", 1},
            {"pop", 0},
            {"assert", 1},
            {"add", 0},
            {"sub", 0},
            {"mul", 0},
            {"div", 0},
            {"mod", 0},
            {"print", 0},
            {"exit", 0}
        };
    public:
        FileParsing(std::string const &filename);
};



#endif