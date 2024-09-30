/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:57:55 by nasreddineh       #+#    #+#             */
/*   Updated: 2024/09/30 10:00:32 by nasreddineh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
#include <stack>
#include <set>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

	public:
		typedef typename Container::iterator iterator;
		MutantStack():std::stack<T>(){};
		MutantStack(MutantStack const & src):std::stack<T>(src){};
		~MutantStack(){};
		MutantStack &operator=(MutantStack const & rhs){new (this) MutantStack(rhs);};
		iterator begin() { return std::begin(c); }
    	iterator end() { return std::end(c); }
    	iterator begin() const { return std::begin(c); }
    	iterator end() const { return std::end(c); }
	private:
		using std::stack<T, Container>::c;
};

#endif