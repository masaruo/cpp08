/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:28:45 by mogawa            #+#    #+#             */
/*   Updated: 2024/05/01 18:24:42 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <set>
#include <functional>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>

template <class Key, class Compare = std::less<Key> >
class Span : public std::multiset<Key, Compare>
{
private:
	unsigned int	max_;
	int				long_;
	int				short_;
	Span(){ return ; };//hidden

	void	update_long_and_short(void)
	{
		if (this->size() <= 1)
			return ;
		assert_non_overflow(*this->rbegin(), *this->begin());
		long_ = *this->rbegin() - *this->begin();
		typename std::multiset<Key, Compare>::const_iterator	crnt = this->begin();
		crnt++;
		typename std::multiset<Key, Compare>::const_iterator	prev = this->begin();
		short_ = *crnt - *prev;
		while (crnt != this->end())
		{
			int gap = *crnt - *prev;
			if (gap < short_)
				short_ = gap;
			crnt++;
			prev++;
		}
	}

	void	assert_has_capacity_to_add(void) const
	{
		if (this->size() < max_)
			return ;
		else
			throw (NoCapacityToAddException());
	}

	void	assert_has_min_2_spans(void) const
	{
		if (this->size() < 2)
			throw (NoSpansExistException());
	}

	void	assert_non_overflow(int bg, int sm) const
	{
		if (sm < 0 && bg > std::numeric_limits<int>::max() + sm)
			throw (std::out_of_range("Int overflow detected."));
		else if (sm > 0 && bg < std::numeric_limits<int>::min() + sm)
			throw (std::out_of_range("Int underflow detected."));
	}

public:
	Span(unsigned int inMax)
	:std::multiset<Key, Compare>()
	,max_(inMax)
	,long_(0)
	,short_(0)
	{
		return ;
	}

	Span(Span const &rhs)
	:std::multiset<Key, Compare>(rhs)
	,max_(rhs.max_)
	,long_(rhs.long_)
	,short_(rhs.short_)
	{
		return ;
	}

	~Span(){ return ; }
	Span &operator=(Span const &rhs)
	{
		if (this != rhs)
		{
			// std::multiset<Key, Compare>::operator=(rhs);
			this->operator=(rhs);
			max_ = rhs.max_;
			long_ = rhs.long_;
			short_ = rhs.short_;
		}
		return (*this);
	}

	void addNumber(int inNum)
	{
		try
		{
			assert_has_capacity_to_add();
			this->insert(inNum);
		}
		catch(std::exception const &e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			update_long_and_short();
		}
		catch(std::out_of_range)
		{
			throw ;
		}
	}

	template <typename Iterator>
	void addNumber(Iterator first, Iterator last)
	{
		unsigned int	cnt = 0;

		while (first != last && cnt < max_)
		{
			this->insert(*first);
			cnt++;
			first++;
		}
		try
		{
			update_long_and_short();
		}
		catch(std::out_of_range)
		{
			throw ;
		}
	}

	int	shortestSpan(void) const
	{
		assert_has_min_2_spans();
		return (short_);
	}

	int	longestSpan(void) const
	{
		assert_has_min_2_spans();
		return (long_);
	}

	class NoSpansExistException : public std::exception
	{
	public:
		char const *what() const throw ()
		{
			return ("there is no span to calculate.");
		}
	};

	class NoCapacityToAddException : public std::exception
	{
	public:
		char const *what() const throw ()
		{
			return ("there is no room left in the capacty to add.");
		}
	};
};

#include "Span.cpp"
