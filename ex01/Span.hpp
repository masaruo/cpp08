/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:32:26 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/27 18:44:16 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>
#include <ostream>

class Span
{
private:
	unsigned int		max_;
	unsigned int		idx_;
	std::vector<int>	vec_;
	Span();//隠蔽されたコンストラクタ
	//helper funcs
	void		assert_has_capacity(void) const;
	void		assert_has_valid_elems(void) const;
	void		assert_int_overflow(int min, int max) const;
public:
	Span(unsigned int max_size);
	Span(Span const &rhs);
	~Span();
	Span &operator=(Span const &rhs);
	void	addNumber(int num_to_add);
	void	addNumber(int min, int max);
	int		shortestSpan(void);
	int		longestSpan(void);
	class SpanIsFullException : public std::exception
	{
	public:
		char const *what() const throw ();
	};
	class SpanHasNoTwoElemsException : public std::exception
	{
	public:
		char const *what() const throw ();
	};
};

std::ostream	&operator<<(std::ostream &os, Span &rhs);

#endif
