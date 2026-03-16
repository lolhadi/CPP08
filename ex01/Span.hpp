/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:09:26 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/16 22:08:11 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
/*
	@ SPAN!!!

	# The best container to use is vector<int> since it dynamic array
		> then after allocation of elements, i think need sorting so easier to compare for the shortest span
		> longest span can be substract from max with min
	# So how what is the best approach?
		> after sorting, can find the min difference between adjacent number
		> so sort, then (-) between number, smallest result is the shortest span
		> in algorithm library can use std::sort
	# Span class:
		> private: unsinged int N, then i need the std::vector<int> _vector for the size of vector
	# member function:

		# addNumber()
			> if my container is full -> if (_vector.size < N)
				> throw full container
			> else
				> push.back into vector

		# shortestSpan()
			> if vector(empty) || vector.size == 1 ; throw vector needs atleast 2 values
			> then create a copy of vector then std::sort from begin till end
			> then loop through the elemnt i duuno?
			> return the smallest span

		# longestSpan()
			> same condition empty or not enough value
			> sort ?? maybe
			> find the min , std::min(begin,end)
			> find the max , std::max(begin, end)
			> return max- min;

		# addRange()
			?
		# exception class
			> need for addnumber
			> need for shortest span
			> need for longest span


*/
class Span
{
	private:
		unsigned int _N; // this is for the maximum capicity
		std::vector<int> _vector;

	public:

		// Constructor
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span& operator=(const Span &copy);

	// Member Function
	void addNumber(int n);
	int shortestSpan()const;
	int longestSpan()const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);

	// Exception Class

	class ContainerFullException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class NotEnoughElementException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

	// Template Implemantation
	template<typename Iterator>
	void Span::addRange(Iterator begin, Iterator end)
	{	size_t tempDist = std::distance(begin, end);
		if (_vector.size() + tempDist > _N)
			throw ContainerFullException();
		else
			_vector.insert(_vector.end(), begin,end);
	}
#endif
