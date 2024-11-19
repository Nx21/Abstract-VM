/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parcing.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:17:37 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/22 16:51:26 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.hpp"
#include <cstddef>
#include <string>

FileParsing::FileParsing(std::string const &filename)
{
    this->_file.open(filename);
    if (!this->_file.is_open())
        throw "can't open file " + filename + "\n";
    this->checker();
    this->exec();
}

void FileParsing::checker()
{
    try {
        std::string s;
        for (size_t nl = 1; getline(_file, s); nl++)
        {
            this->parseLine(nl, s);
        }
    } catch (std::string const &s) {
        throw "syntex error: " + s;
    }
    
}

void FileParsing::parseLine(size_t nl, std::string &s)
{
    t_commandList cmd ;
    cmd.line_number = nl;
    trim(s, "\n\t ");
    if (s.find(";;") == 0)
        return;
    size_t pos = s.find(' ') != s.npos ? s.find(' ') : s.size(); 
    std::string key = s.substr(0, pos);
    trim(key, " \n");
    std::string val = s.substr(pos);
    trim(val, " \n");
    auto it = this->method_map.find(key);
    if(it == this->method_map.end())
        throw "line " + std::to_string(nl) + "invalid syntax " + key + "\n";
    cmd.command = key;
    if(it->second)
    {
        pos = val.find('(');
        if(pos == val.npos )
            throw "line " + std::to_string(nl) +  ": messing '(' " + val;
        
        
    }
    else if (val != "")
        throw "line " + std::to_string(nl) +  ": invalid value " + val;
    this->_listCommand.push_back(cmd);
}

void FileParsing::exec()
{
    for(auto l: this->_listCommand)
    {
        std::cout << l.line_number << " " << l.command << " " << l.value << " "<< l.type << std::endl;
    }
}