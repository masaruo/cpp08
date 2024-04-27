/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:24:26 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/27 17:56:29 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <stack>
#include <ostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack():std::stack<T>(){ return ; }
	MutantStack(MutantStack const &rhs):std::stack<T>(rhs){ return ; }
	~MutantStack(){ return ; }
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
		{
			std::stack<T>::operator = (rhs);
		}
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator	begin(void)
	{
		return (this->c.begin());
	}
	iterator	end(void)
	{
		return (this->c.end());
	}

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator	rbegin(void)
	{
		return (this->c.rbegin());
	}
	reverse_iterator	rend(void)
	{
		return (this->c.rend());
	}

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator	begin(void) const
	{
		return (this->c.begin());
	}
	const_iterator	end(void) const
	{
		return (this->c.end());
	}
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator	rbegin(void) const
	{
		return (this->c.rbegin());
	}
	const_reverse_iterator	rend(void) const
	{
		return (this->c.rend());
	}
};

template <typename T>
std::ostream &operator<<(std::ostream &os, MutantStack<T> const &rhs)
{
	os << "Stack contains ";
	for (typename MutantStack<T>::const_iterator iter = rhs.begin(); iter < rhs.end(); iter++)
	{
		os << *iter << " | ";
	}
	os << std::endl;
	return (os);
}

#endif
