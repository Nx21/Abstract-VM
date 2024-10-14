/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:24:18 by nhanafi           #+#    #+#             */
/*   Updated: 2024/10/14 15:35:47 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TRIM_HPP
# define TRIM_HPP

#include <string>

inline void ltrim(std::string &s, std::string w)
{
    size_t start = s.find_first_not_of(w);
    s = (start == std::string::npos) ? "" : s.substr(start);
}
 
inline void rtrim(std::string &s, std::string w)
{
    size_t end = s.find_last_not_of(w);
    s =  (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
inline void trim(std::string &s, std::string w)
{
    rtrim(s,w);
    ltrim(s,w);
}
#endif