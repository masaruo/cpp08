/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:36:10 by mogawa            #+#    #+#             */
/*   Updated: 2024/05/01 13:46:19 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <vector>

void	cout(std::string const &msg)
{
	std::cout << "*" << msg << "*" << std::endl;
}

template <typename Iter>
void	printContent(Iter first, Iter last)
{
	for (Iter i = first; i != last; i++)
		std::cout << "[" << *i << "]";
	std::cout << std::endl;
}

int main()
{
	cout("mstack check");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(42);
	cout("5, 17, 42 in mutant stack normal order");
	printContent(mstack.begin(), mstack.end());
	cout("top");
	std::cout << mstack.top() << std::endl;
	cout("empty");
	std::cout << mstack.empty() << std::endl;
	cout ("size");
	std::cout << mstack.size() << std::endl;
	cout("mstack reverse iter");
	printContent(mstack.rbegin(), mstack.rend());
	cout("pop twice");
	mstack.pop();
	mstack.pop();
	printContent(mstack.begin(), mstack.end());
	mstack.pop();
	// mstack.pop();//segfault
	printContent(mstack.begin(), mstack.end());

	cout("mstack with container vector check");
	MutantStack<int, std::vector<int> > mvecstack;
	mvecstack.push(5);
	mvecstack.push(17);
	mvecstack.push(42);
	cout("5, 17, 42 in mutant vector normal order");
	printContent(mvecstack.begin(), mvecstack.end());
	cout("top");
	std::cout << mvecstack.top() << std::endl;
	cout("empty");
	std::cout << mvecstack.empty() << std::endl;
	cout ("size");
	std::cout << mvecstack.size() << std::endl;
	cout("mutant vector reverse");
	printContent(mvecstack.rbegin(), mvecstack.rend());
	cout("pop twice");
	mvecstack.pop();
	mvecstack.pop();
	printContent(mvecstack.begin(), mvecstack.end());
	mvecstack.pop();
	// mstack.pop();//segfault
	printContent(mvecstack.begin(), mvecstack.end());

	cout("std::list");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(42);
	cout("5, 17, 42 in lst normal order");
	printContent(lst.begin(), lst.end());
	cout("empty");
	std::cout << lst.empty() << std::endl;
	cout ("size");
	std::cout << lst.size() << std::endl;
	cout("normal list reverse");
	printContent(lst.rbegin(), lst.rend());
	cout("pop twice");
	lst.pop_back();
	lst.pop_back();
	printContent(lst.begin(), lst.end());
	lst.pop_back();
	// lst.pop_back();//segfault
	printContent(lst.begin(), lst.end());



// MutantStack<int, std::list<int> > mstack;
// MutantStack<int, std::list<int> > clone;
// mstack.push(42);
// mstack.push(-42);
// std::cout << "mstack "<< mstack << std::endl;
// std::cout << "mstack top "<< mstack.top() << std::endl;
// std::cout << "mstack size "<< mstack.size() << std::endl;
// clone = mstack;
// std::cout << "clone " << clone << std::endl;
// mstack.pop();
// std::cout << "mstack after pop "<< mstack << std::endl;
// std::cout << "clone after mstack pop " << clone << std::endl;
// MutantStack<int, std::list<int> > copy(clone);
// std::cout << "copy clone " << copy << std::endl;
// copy.push(4242);
// std::cout << "copy " << copy << std::endl;
// std::cout << "clone " << clone << std::endl;
return 0;
}
