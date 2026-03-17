/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 08:54:02 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/17 09:52:56 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
/*
	@ The Problem??:
		> Got a use std::stack, but we cannot iterate through it
		> We can only accees the top() element
		> No NO NO .begin() and end(), LOOPS NO NO!!

	@ Solution:
		> Create a MutantStack that inherit from std::stack
		> Get all the Stack functionality
		> MUST BE ITERATEABLE!

	@ What is std::stack?
		> stack is a container adapter, that give stack function LIFO
		> its build on top of std::deque
		> has protected member : Container c;
		> can access using this-> c;
	@ Then what?
		> mutantStack inherit from std::stack
		> remember stack dont have iterator but the deque has, so access the container c to use begin, end
		> then create iterator typedef = create an alias called iterator
		> implement the begin() and end()
		> OCF need in template cause we pass a container
		> need iterator begin() and end() for modifiable access
		> need const_iterator begin() end () const for const access
		> typedef typename= tell the compiler that this is a type
		> std::stack<T>::container_type::iterator = The iterator type of the container inside stack<T>
*/
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Iterator typedef, define the iterator
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;


		// iterator function
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;
};

// Template Implementation
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin()const
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end()const
{
	return this->c.end();
}

#endif
