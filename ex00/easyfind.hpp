/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:09:36 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/12 08:12:20 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP


/*
	# using the std::find() parameter = iterator.begin, iterator.ends, value(what we want)
	# so every container has iterator ex: vector<int>:: iterator it;
	# so we want template function with container type:
		template <typename T>
		ReturnType easyfind(T &container, int value)
		> T can be any container:
			* std::vector<int>
			* std::list<int>
			* std::deque<int>

	# So the return type will be vector<int> -> so typename T::iterator easyfind
		> typename T will be the auto container used
		> typename is telling the compiler it is a type not a variable
		> T = the type of container itself
		> T::iterator = the iterator type of that container
	# the Algorithm
		> so it will use std::find, from begin till end with the value we want to search
			> compare the iterator to the container.end()
				> if (iterator === container.end())
					> throw exception not found
				> else return iterator
	# why return iterator??
		> so i can print the value and modify the value, if i pass the pointer iterator i cannot modify the element
*/
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what()const throw(){
			return ("Value not found");}
};

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator result = std::find(container.begin(), container.end(), value);
	if (result == container.end())
		throw NotFoundException();
	return result;
}

#endif
