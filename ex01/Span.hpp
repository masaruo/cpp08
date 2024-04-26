/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:32:26 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/26 15:15:56 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>
#include <ostream>

class Span
{
enum type_e { shortest_, longest_, validate_};
private:
	unsigned int		max_;
	unsigned int		idx_;
	std::vector<int>	vec_;
	Span();//隠蔽されたコンストラクタ
	//helper funcs
	void		assert_has_capacity(void) const;
	void		assert_has_valid_elems(void);
	std::size_t	get_long_span(type_e) const;
	std::size_t	get_short_span(void) const;
public:
	Span(unsigned int max_size);
	Span(Span const &rhs);
	~Span();
	Span &operator=(Span const &rhs);
	void		addNumber(int num_to_add);
	void		addNumber(int min, int max);
	std::size_t	shortestSpan(void);
	std::size_t	longestSpan(void);
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
