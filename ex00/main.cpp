/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:11:48 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/12 08:12:25 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "=== Test 1: Vector - Element Found ===" << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(42);
		vec.push_back(5);

		try
		{
			std::vector<int>::iterator result = easyfind(vec, 42);
			std::cout << "Found: " << *result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 2: Vector - Element Not Found ===" << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);

		try
		{
			std::vector<int>::iterator result = easyfind(vec, 99);
			std::cout << "Found: " << *result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 3: List - Element Found ===" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);

		try
		{
			std::list<int>::iterator result = easyfind(lst, 20);
			std::cout << "Found: " << *result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 4: List - Element Not Found ===" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);

		try
		{
			std::list<int>::iterator result = easyfind(lst, 100);
			std::cout << "Found: " << *result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 5: Deque - Element Found ===" << std::endl;
	{
		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);

		try
		{
			std::deque<int>::iterator result = easyfind(deq, 200);
			std::cout << "Found: " << *result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 6: Deque - Element Not Found ===" << std::endl;
	{
		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);

		try
		{
			std::deque<int>::iterator result = easyfind(deq, 500);
			std::cout << "Found: " << *result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 7: Empty Vector ===" << std::endl;
	{
		std::vector<int> vec;

		try
		{
			std::vector<int>::iterator result = easyfind(vec, 1);
			std::cout << "Found: " << *result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 8: Modifying Through Iterator ===" << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);

		try
		{
			std::vector<int>::iterator result = easyfind(vec, 2);
			std::cout << "Found: " << *result << std::endl;

			// Modify through iterator
			*result = 99;
			std::cout << "After modification: " << *result << std::endl;

			// Verify original vector changed
			std::cout << "Vector contents: ";
			for (size_t i = 0; i < vec.size(); i++)
				std::cout << vec[i] << " ";
			std::cout << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
