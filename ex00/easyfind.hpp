/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:00:27 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/27 18:05:28 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
int	easyfind(T const &container, int target_n)
{
	typename T::const_iterator	it = container.begin();
	typename T::const_iterator	end = container.end();
	typename T::const_iterator	loc;

	loc = std::find(it, end, target_n);
	if (loc == end)
		throw (std::out_of_range("index is out of range."));
	else
		return (*loc);
}
