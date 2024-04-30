/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:53:18 by mogawa            #+#    #+#             */
/*   Updated: 2024/05/01 00:10:03 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>

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

int main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> dq;

	init_(vec);
	init_(lst);
	init_(dq);

	std::vector<int>::iterator vec_iter = easyfind(vec, 5);
	std::cout << *vec_iter << std::endl;
	print(vec, "vector check");
	std::vector<int> const vec_const(vec);
	print(vec_const, "vec_const copy constructor");
	*vec_iter = -100000;
	print(vec, "after amend of vec");
	std::cout << vec_iter - vec.begin() << std::endl;

	// list
	std::cout << "lst check" << std::endl;
	std::list<int>::iterator lst_iter = easyfind(lst, 1);
	std::cout << *lst_iter << std::endl;
	print(vec, "lst check");
	std::list<int> const lst_const(lst);
	print(lst_const, "lst_const copy constructor");
	*lst_iter = -100000;
	print(lst, "after amend");
	// std::cout << lst_iter - lst.begin() << std::endl;//error list does not have -

	// deque
	std::cout << std::endl;
	std::deque<int>::iterator dq_iter = easyfind(dq, 8);
	std::cout << *dq_iter << std::endl;
	print(dq, "dq check");
	std::deque<int> const dq_const(dq);
	print(dq_const, "const copy constructor");
	*dq_iter = -100000;
	print(dq, "after amend of dq");
	std::cout << dq_iter - dq.begin() << std::endl;

	return (0);
}
