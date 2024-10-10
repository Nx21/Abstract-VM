/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:22:14 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/10/10 10:16:44 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/common.hpp"
#include <cstddef>
#include <string>


void Command::command(std::string const &str){
    std::string s = str;
    trim(s, " \n\t");
    size_t pos = s.find(' ') != s.npos ? s.find(' ') : s.size(); 
    std::string key = s.substr(0, pos);
    trim(key, " \n");
    std::string val = s.substr(pos);
    trim(val, " \n");
    auto it = this->method_map.find(key);
    if(it == this->method_map.end())
        throw "invalid syntax " + key + "\n";
    (this->*it->second)(val);
}

void Command::push(std::string const &str){
    if(str == "" || str.find_first_not_of("1234567890.-+"))
        throw "invalid syntax " + str + "\n";
    this->_stack.push(str);
}

void Command::assert(std::string const &str){
    if(str == "" || str.find_first_not_of("1234567890.-+"))
        throw "invalid syntax " + str + "\n";
    this->_stack.Assert(str);
}

void Command::pop(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    this->_stack.pop();
}

void Command::dump(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    this->_stack.dump();
}

void Command::add(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    this->_stack.add();
}

void Command::sub(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    this->_stack.sub();
}

void Command::mod(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    this->_stack.mod();
}

void Command::div(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    this->_stack.div();
}

void Command::print(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    this->_stack.print();
}

void Command::exit(std::string const &str){
    if(str != "")
        throw "invalid syntax " + str + "\n";
    
}

