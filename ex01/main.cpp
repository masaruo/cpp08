/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:05:37 by mogawa            #+#    #+#             */
/*   Updated: 2024/05/01 18:25:11 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits>
#include <vector>

int const int_max = std::numeric_limits<int>::max();
int const int_min = std::numeric_limits<int>::min();

template <typename Iter>
void print(Iter first, Iter last)
{
	for (Iter i = first; i != last; i++)
	{
		std::cout << "[" <<  *i << "]";
	}
	std::cout << std::endl;
}

int main(void)
{

	try
	{
		Span<int>	sp(5);
		std::cout << "assignment example and adding more than size" << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);//error there is no room to add
		print(sp.begin(), sp.end());
		std::cout << "longest " << sp.longestSpan() << std::endl;
		std::cout << "shortest " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "overflow test" << std::endl;
		Span<int> *sp = new Span<int>(5);
		sp->addNumber(int_max);
		sp->addNumber(3);
		sp->addNumber(17);
		sp->addNumber(9);
		sp->addNumber(-1);
		print(sp->begin(), sp->end());
		std::cout << "longest " << sp->longestSpan() << std::endl;
		std::cout << "shortest " << sp->shortestSpan() << std::endl;
		delete sp;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "underflow test" << std::endl;
		Span<int> *sp = new Span<int>(5);
		sp->addNumber(int_min);
		sp->addNumber(0);
		print(sp->begin(), sp->end());
		std::cout << "longest " << sp->longestSpan() << std::endl;
		std::cout << "shortest " << sp->shortestSpan() << std::endl;
		delete sp;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "iterator test" << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < 10000; i++)
		{
			vec.push_back(i);
		}
		Span<int> sp(100);
		sp.addNumber(vec.begin(), vec.end());
		print(sp.begin(), sp.end());
		std::cout << "longest " << sp.longestSpan() << std::endl;
		std::cout << "shortest " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
