/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:53:02 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/17 10:04:13 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include<iostream>
#include <list>

int main()
{
	std::cout << "=== Test 1: Subject Example with MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size after pop: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Stack contents (using iterators):" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		std::cout << "Can create std::stack from MutantStack!" << std::endl;
	}

	std::cout << "\n=== Test 2: Same Test with std::list (should match!) ===" << std::endl;
	{
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << "Back: " << mlist.back() << std::endl;

		mlist.pop_back();

		std::cout << "Size after pop: " << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;

		std::cout << "List contents (using iterators):" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== Test 3: String MutantStack ===" << std::endl;
	{
		MutantStack<std::string> mstack;

		mstack.push("Hello");
		mstack.push("World");
		mstack.push("From");
		mstack.push("MutantStack");

		std::cout << "String stack contents:" << std::endl;
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}

	std::cout << "\n=== Test 4: Const MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		const MutantStack<int> const_stack = mstack;

		std::cout << "Const stack contents:" << std::endl;
		for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}

	std::cout << "\n=== Test 5: Empty MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;

		std::cout << "Empty stack - begin == end? " << (mstack.begin() == mstack.end() ? "Yes" : "No") << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
	}

	std::cout << "\n=== Test 6: Modify Through Iterator ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		std::cout << "Before modification:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Modify through iterator
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			*it *= 10;
		}

		std::cout << "After multiplication by 10:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 7: Copy Constructor ===" << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(10);
		mstack1.push(20);
		mstack1.push(30);

		MutantStack<int> mstack2 = mstack1;

		std::cout << "Original stack:" << std::endl;
		for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Copied stack:" << std::endl;
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 8: Assignment Operator ===" << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(100);
		mstack1.push(200);

		MutantStack<int> mstack2;
		mstack2.push(1);

		mstack2 = mstack1;

		std::cout << "After assignment:" << std::endl;
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 9: Large Stack ===" << std::endl;
	{
		MutantStack<int> mstack;

		for (int i = 0; i < 100; i++)
		{
			mstack.push(i);
		}

		std::cout << "Stack size: " << mstack.size() << std::endl;
		std::cout << "First 10 elements: ";

		MutantStack<int>::iterator it = mstack.begin();
		for (int i = 0; i < 10; i++)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 10: All Stack Operations Still Work ===" << std::endl;
	{
		MutantStack<int> mstack;

		std::cout << "Empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;

		mstack.push(42);
		std::cout << "After push(42) - Empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(100);
		std::cout << "After push(100) - Top: " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "After pop() - Top: " << mstack.top() << std::endl;
	}

	return 0;
}
