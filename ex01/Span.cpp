/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:12:16 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/16 22:38:16 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _N(N){}
Span::~Span(){}
Span::Span(const Span &copy): _N(copy._N), _vector(copy._vector){}
Span& Span::operator=(const Span &copy)
{
	if(this != &copy)
	{
		_N = copy._N;
		_vector = copy._vector;
	}
	return *this;
}

// Exception Implementation
const char* Span::ContainerFullException::what() const throw()
{
	return "Container is FULL";
}
const char* Span::NotEnoughElementException::what() const throw()
{
	return "Not Enough Element to calculate Span";
}

// member Function Implementation
void Span::addNumber(int n)
{
	if (_vector.size() >= this-> _N)
		throw ContainerFullException();
	else
		_vector.push_back(n);
}

int Span::shortestSpan()const
{
	if (_vector.empty() || _vector.size() == 1)
		throw NotEnoughElementException();
	std::vector<int> sorted =	_vector;
	std::sort(sorted.begin(), sorted.end());
	unsigned int smallest = UINT_MAX;
	for(size_t i = 0; i < sorted.size() - 1; i++)
	{
		unsigned int diff =sorted[i + 1] - sorted[i];
		if (diff < smallest)
			smallest = diff;
	}
	return smallest;
}

int Span::longestSpan()const
{
	if (_vector.empty() || _vector.size() == 1)
		throw NotEnoughElementException();
	std::vector<int>::const_iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::const_iterator max = std::max_element(_vector.begin(), _vector.end());
	return (*max - *min);
}
