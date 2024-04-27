/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:53:18 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/27 18:09:39 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int const SIZE = 3;

template <typename T>
void	init_(T &container)
{
	typename T::iterator	start = container.begin();
	typename T::iterator	end = container.end();
	int	i = 1;
	while (start != end)
	{
		*start = i;
		i++;
		start++;
	}
}

int main(void)
{
	std::vector<int> vec(SIZE);
	std::list<int> lst(SIZE);
	std::deque<int> dq(SIZE);

	init_(vec);
	init_(lst);
	init_(dq);
	try
	{
		int vec_res = easyfind<std::vector<int> >(vec, 1);
		std::cout << "vec res = " << vec_res << std::endl;
		int	lst_res = easyfind<std::list<int> >(lst, 2);
		std::cout << "lst res = " << lst_res << std::endl;
		int dq_res = easyfind<std::deque<int> >(dq, 3);
		std::cout << "dq res = " << dq_res << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "some other error." << std::endl;
	}
	return (0);
}
