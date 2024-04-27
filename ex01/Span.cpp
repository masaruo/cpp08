/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:32:07 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/27 20:50:57 by mogawa           ###   ########.fr       */
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

void	Span::assert_int_overflow(int min, int max) const
{
	unsigned int u_max;
	unsigned int u_min;

	if (min < 0)
		u_min = static_cast<unsigned int>(min * -1);
	else
		u_min = static_cast<unsigned int>(min);
	if (max < 0)
		u_max = static_cast<unsigned int>(max * -1);
	else
		u_max = static_cast<unsigned int>(max);
	if (u_max > u_min - std::numeric_limits<int>::max())
		throw (std::overflow_error("overflow error."));
}

void	Span::assert_has_capacity(void) const
{
	if (idx_ < max_)
		return ;
	else
		throw (SpanIsFullException());
}

void	Span::assert_has_valid_elems(void) const
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
	random = random % (max - min + 1) + min;
	return (random);
}

void	Span::addNumber(int min, int max)
{
	try
	{
		assert_has_capacity();
		assert_int_overflow(min, max);
		std::srand(std::time(NULL));
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
	catch(std::overflow_error const &e)
	{
		// std::cerr << e.what() << std::endl;
		throw ;
	}
	catch(std::exception)
	{
		throw ;
	}
}

int	Span::shortestSpan(void)
{
	int min_span;
	try
	{
		assert_has_valid_elems();
		std::sort(vec_.begin(), vec_.end());	
		std::vector<int>::const_iterator	crnt = vec_.begin();
		std::vector<int>::const_iterator	next = crnt + 1;
		assert_int_overflow(*crnt, *next);
		min_span = *next - *crnt;
		while (next != vec_.end())
		{
			assert_int_overflow(*crnt, *next);
			int span = *next - *crnt;
			if (span < min_span)
				min_span = span;
			next++;
			crnt++;
		}
	}
	catch(SpanHasNoTwoElemsException const &e)
	{
		throw ;
	}
	return (min_span);
}

int Span::longestSpan(void)
{
	int	max_span = 0;
	try
	{
		assert_has_valid_elems();
		std::sort(vec_.begin(), vec_.end());
		assert_int_overflow(vec_.front(), vec_.back());
		max_span = vec_.back() - vec_.front();
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
	os << rhs.longestSpan() << " is longest span and shortest is " << rhs.shortestSpan() << std::endl;
	return (os);
}
