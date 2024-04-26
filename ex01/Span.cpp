/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:32:07 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/26 16:18:10 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

// helper
void	Span::assert_has_capacity(void) const
{
	if (idx_ < max_)
		return ;
	else
		throw (SpanIsFullException());
}

void	Span::assert_has_valid_elems(void)
{
	if (vec_.size() == 0 || idx_ == 0 || idx_ == 1)
		throw (SpanHasNoTwoElemsException());
}

Span::Span(){ return ; }

Span::Span(unsigned int max_size)
:max_(max_size)
,idx_(0)
,vec_(max_)
{
	return ;
}

Span::Span(Span const &rhs)
:max_(rhs.max_)
,idx_(rhs.idx_)
,vec_(rhs.vec_)
{
	return ;
}

Span::~Span(){ return ; }

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		max_ = rhs.max_;
		idx_ = rhs.idx_;
		vec_ = rhs.vec_;
	}
	return (*this);
}

void	Span::addNumber(int num_to_add)
{
	try
	{
		assert_has_capacity();
		vec_.at(idx_) = num_to_add;
		idx_++;
	}
	catch (SpanIsFullException const &e)
	{
		// std::cerr << e.what() << std::endl;
		throw ;
	}
}

static int	get_ranged_rand(int min, int max)
{
	int random = std::rand();
	if (max > std::numeric_limits<int>::max() + min)
		throw (std::overflow_error("overflow error for your min max range"));
	random = random % (max - min + 1) + min;
	return (random);
}

void	Span::addNumber(int min, int max)
{
	try
	{
		std::srand(std::time(NULL));
		assert_has_capacity();
		std::vector<int>::iterator it = vec_.begin();
		std::vector<int>::const_iterator end = vec_.end();
		while (it < end)
		{
			*it = get_ranged_rand(min, max);
			it++;
			idx_++;
		}
	}
	catch(SpanIsFullException const &e)
	{
		// std::cerr << e.what() << '\n';
		throw ;
	}
}

std::size_t	Span::shortestSpan(void)
{
	std::size_t	min_span = std::numeric_limits<std::size_t>::max();
	try
	{
		std::sort(vec_.begin(), vec_.end());	
		assert_has_valid_elems();
		std::vector<int>::iterator	crnt = vec_.begin();
		std::vector<int>::iterator	next = crnt + 1;
		while (next != vec_.end())
		{
			std::size_t span = static_cast<std::size_t>(*next - *crnt);
			if (span < min_span)
				min_span = span;
			next++;
			crnt++;
		}
	}
	catch(SpanHasNoTwoElemsException const &e)
	{
		// std::cerr << e.what() << std::endl;
		throw ;
	}
	return (min_span);
}

std::size_t Span::longestSpan(void)
{
	std::size_t	max_span = 0;
	try
	{
		std::sort(vec_.begin(), vec_.end());
		assert_has_valid_elems();
		max_span = static_cast<std::size_t>(vec_.back() - vec_.front());
		return (max_span);
	}
	catch(SpanHasNoTwoElemsException const &e)
	{
		// std::cerr << e.what() << '\n';
		throw ;
	}
	return (max_span);
}

char const *Span::SpanIsFullException::what() const throw ()
{
	return ("Span is already full.");
}

char const *Span::SpanHasNoTwoElemsException::what() const throw ()
{
	return ("Span has less than 2 elements.");
}

std::ostream	&operator<<(std::ostream &os, Span &rhs)
{
	os << "short[" << rhs.shortestSpan() << "]|long[" << rhs.longestSpan() << "]" << std::endl;
	return (os);
}
