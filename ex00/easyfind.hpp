/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:00:27 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/30 23:12:59 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator	easyfind(T const &container, int target_n)
{
	typename T::const_iterator	begin = container.begin();
	typename T::const_iterator	end = container.end();

	return (std::find(begin, end, target_n));
}

template <typename T>
typename T::iterator	easyfind(T &container, int target_n)
{
	typename T::iterator	begin = container.begin();
	typename T::iterator	end = container.end();

	return (std::find(begin, end, target_n));
}
