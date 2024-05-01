/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:24:26 by mogawa            #+#    #+#             */
/*   Updated: 2024/05/01 10:56:18 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <stack>
#include <ostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack():std::stack<T, Container>(){ return ; }
	MutantStack(MutantStack const &rhs):std::stack<T, Container>(rhs){ return ; }
	~MutantStack(){ return ; }
	MutantStack &operator=(MutantStack const &rhs)
	{
		std::stack<T, Container>::operator = (rhs);//!括弧無いと動かない！operator=は関数！
		return (*this);
	}

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	iterator	begin(void)
	{
		return (this->c.begin());//! std::stack<T>::begin()
	}
	iterator	end(void)
	{
		return (this->c.end());
		// return (std::stack<T>::end());こっちのほうがわかりやすいかな？
	}

	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator	rbegin(void)
	{
		return (this->c.rbegin());
	}
	reverse_iterator	rend(void)
	{
		return (this->c.rend());
	}

	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
	const_iterator	begin(void) const
	{
		return (this->c.begin());
	}
	const_iterator	end(void) const
	{
		return (this->c.end());
	}
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator	rbegin(void) const
	{
		return (this->c.rbegin());
	}
	const_reverse_iterator	rend(void) const
	{
		return (this->c.rend());
	}
};

template <typename T, typename Container>
std::ostream &operator<<(std::ostream &os, MutantStack<T, Container> const &rhs)
{
	os << "Stack contains ";
	for (typename MutantStack<T, Container>::const_iterator iter = rhs.begin(); iter != rhs.end(); iter++)
	{
		os << *iter << " | ";
	}
	os << std::endl;
	return (os);
}

#endif
