/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:36:10 by mogawa            #+#    #+#             */
/*   Updated: 2024/04/27 18:03:54 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
MutantStack<int> mstack;
MutantStack<int> clone;
mstack.push(42);
mstack.push(-42);
std::cout << "mstack "<< mstack << std::endl;
std::cout << "mstack top "<< mstack.top() << std::endl;
std::cout << "mstack size "<< mstack.size() << std::endl;
clone = mstack;
std::cout << "clone " << clone << std::endl;
mstack.pop();
std::cout << "mstack after pop "<< mstack << std::endl;
std::cout << "clone after mstack pop " << clone << std::endl;
MutantStack<int> copy(clone);
std::cout << "copy clone " << copy << std::endl;
copy.push(4242);
std::cout << "copy " << copy << std::endl;
std::cout << "clone " << clone << std::endl;
return 0;
}
