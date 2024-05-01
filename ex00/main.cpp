/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:53:18 by mogawa            #+#    #+#             */
/*   Updated: 2024/05/01 10:01:04 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>

int const SIZE = 10;

template <typename T>
void	init_(T &container)
{
	for (int i = 0; i < SIZE; i++)
	{
		container.push_back(i);
	}
}

template <typename T>
void	print(T const &c, std::string const &msg)
{
	std::cout << msg << std::endl;
	typename T::const_iterator it = c.begin();
	for (; it != c.end(); it++)
	{
		std::cout << *it << " | ";
	}
	std::cout << std::endl;
}

template <typename T, typename V>
void	copy(T const &from, V &to)
{
	typename T::const_iterator iterfrom = from.begin();
	typename T::const_iterator endfrom = from.end();

	while (iterfrom != endfrom)
	{
		to.push_back(*iterfrom * 2);
		iterfrom++;
	}
}

int main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> dq;

	init_(vec);
	{
		std::vector<int>::iterator vec_iter = easyfind(vec, 5);
		std::cout << *vec_iter << std::endl;
		print(vec, "vector check");

		std::cout << "out of range check" << std::endl;
		std::vector<int>::iterator out_of_range = easyfind(vec,100);
		if (out_of_range == vec.end())
			std::cout << "out of range" << std::endl;
		else
			std::cout << "in range" << std::endl;
		std::vector<int> const vec_const(vec);
		std::vector<int>::const_iterator vec_const_it = easyfind(vec_const, 9);
		print(vec_const, "vec_const copy constructor and easyfind 9");
		std::cout << *vec_const_it << std::endl;
		*vec_iter = -100;
		
		print(vec, "after amend of vec and vec_iter - vec_begin = 5");
		std::cout << vec_iter - vec.begin() << std::endl;

		copy<std::vector<int>, std::list<int> >(vec, lst);
	}
	{
	// list
		std::cout << std::endl;
		std::list<int>::iterator lst_iter = easyfind(lst, 6);
		std::cout << *lst_iter << std::endl;
		print(lst, "lst check");
		std::list<int>	lst_copy_operator;
		lst_copy_operator = lst;
		print(lst_copy_operator, "lst copy operator");
		*lst_iter = 42;
		print(lst, "after amend");
		// std::cout << lst_iter - lst.begin() << std::endl;//error list does not have -
	}

	copy<std::list<int>, std::deque<int> >(lst, dq);

	// deque
	std::cout << std::endl;
	std::deque<int>::iterator dq_iter = easyfind(dq, 24);
	std::cout << *dq_iter << std::endl;
	print(dq, "dq check");
	std::deque<int> const dq_const(dq);
	print(dq_const, "const copy constructor");
	*dq_iter = 424242;
	print(dq, "after amend of dq");
	std::cout << dq_iter - dq.begin() << std::endl;

	return (0);
}
