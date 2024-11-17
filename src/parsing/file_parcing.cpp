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

FileParising::FileParising(std::string const &filename)
{
    this->_file.open(filename);
    if (!this->_file.is_open())
        throw "can't open file " + filename + "\n";
    this->checker();
    this->exec();
}

void FileParising::checker()
{
    try {
        std::string s;
        for (size_t nl; getline(_file, s); nl++)
        {
            this->parseLine(nl, s);
        }
    } catch (std::string const &s) {
        throw "syntex error: " + s;
    }
    
}

void FileParising::parseLine(size_t nl, std::string &s)
{
    t_commandList cmd ;
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
        
    }
    else if (val != "")
        throw "line " + std::to_string(nl) +  ": invalid value " + val;
    this->_listCommand.push_back(cmd);
}