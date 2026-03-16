/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:40:00 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/16 22:38:13 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== Test 1: Subject Example ===" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test 2: Try to Add Too Many ===" << std::endl;
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);

		try
		{
			sp.addNumber(4);  // Should throw!
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 3: Not Enough Elements ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(42);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 4: Empty Span ===" << std::endl;
	{
		Span sp(10);

		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 5: Large Span with addRange ===" << std::endl;
	{
		Span sp(10000);
		std::vector<int> numbers;

		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
			numbers.push_back(rand());

		sp.addRange(numbers.begin(), numbers.end());

		std::cout << "Added 10,000 random numbers" << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test 6: addRange with Too Many Elements ===" << std::endl;
	{
		Span sp(5);
		std::vector<int> numbers;

		for (int i = 0; i < 10; i++)
			numbers.push_back(i);

		try
		{
			sp.addRange(numbers.begin(), numbers.end());
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Test 7: Negative Numbers ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(5);
		sp.addNumber(10);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test 8: Duplicate Numbers ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(15);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Test 9: Copy Constructor ===" << std::endl;
	{
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);

		Span sp2(sp1);
		sp2.addNumber(4);
		sp2.addNumber(5);

		std::cout << "sp1 shortest: " << sp1.shortestSpan() << std::endl;
		std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
	}

	std::cout << "\n=== Test 10: Assignment Operator ===" << std::endl;
	{
		Span sp1(3);
		sp1.addNumber(10);
		sp1.addNumber(20);
		sp1.addNumber(30);

		Span sp2(10);
		sp2 = sp1;

		std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
	}

	return 0;
}
