/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:58:18 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/30 17:52:29 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <vector>

template<typename T>
class MutantStack
{
private:
	std::vector<T>	stack;
public:
	MutantStack();
	MutantStack(const MutantStack& copy);
	const MutantStack&	operator=(const MutantStack& other);
	~MutantStack();
	void	pop() const; //removes the top element
	bool	empty() const; //checks whether the container adaptor is empt
	T*		top() const; //accesses the top element
	size_t	size() const; //returns the number of elements
	void	push(T& val) //inserts element at the top
	class Iterator
	{
		private:
			std::vector<T>::iterator vIt;
		public:
			Iterator();
			Iterator(const Iterator& copy);
			~Iterator();
			
	}
};

