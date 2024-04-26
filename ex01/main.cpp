/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:05:37 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/26 16:22:14 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int const INTMAX = std::numeric_limits<int>::max();
int const INTMIN = std::numeric_limits<int>::min();

void	test1(void)
{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;
}

void	testVecSize0AndAddElem()
{
	Span sp = Span(0);

	sp.addNumber(1);
	std::cout << sp << std::endl;
}

void	TestIntMaxMin()
{
	Span sp = Span(2);
	
	sp.addNumber(std::numeric_limits<int>::max());
	sp.addNumber(std::numeric_limits<int>::min());
	std::cout << sp << std::endl;
}

void	testOnlySameNum()
{
	Span sp = Span(4);

	sp.addNumber(2);
	sp.addNumber(2);
	sp.addNumber(2);
	sp.addNumber(2);
	std::cout << sp << std::endl;
}

void	adhocTest(int min, int max, unsigned int size)
{
	Span sp = Span(size);

	sp.addNumber(min, max);
	std::cout << sp << std::endl;
}

int	main(void)
{
	try
	{
		test1();
		// testVecSize0AndAddElem();
		// TestIntMaxMin();å
		// testOnlySameNum();
		// adhocTest(-100, 100, 10000);
	}
	catch (Span::SpanIsFullException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Span::SpanHasNoTwoElemsException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "some other exception" << std::endl;
	}
	return(0);
}
