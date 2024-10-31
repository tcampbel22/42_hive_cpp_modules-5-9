/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:06:10 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/31 17:57:14 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, template <typename, typename> class Container>
MutantStack<T, Container>::MutantStack() = default;

template<typename T, template <typename, typename> class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& copy) { mutantStack = copy.mutantStack; }

template<typename T, template <typename, typename> class Container>
const MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other) 
{
	if (this != &other)
		mutantStack = other.mutantStack;
	return *this;
}

template<typename T, template <typename, typename> class Container>
MutantStack<T, Container>::~MutantStack() = default;

template<typename T, template <typename, typename> class Container>
void 	MutantStack<T, Container>::push(const T& val) { mutantStack.push_back(val); }

template<typename T, template <typename, typename> class Container>
void 	MutantStack<T, Container>::pop() { mutantStack.pop_back(); }

template<typename T, template <typename, typename> class Container>
T&		MutantStack<T, Container>::top() { return mutantStack.back(); }

template<typename T, template <typename, typename> class Container>
const T&		MutantStack<T, Container>::top() const { return mutantStack.cback(); }

template<typename T, template <typename, typename> class Container>
bool	MutantStack<T, Container>::empty() const { return mutantStack.empty(); }

template<typename T, template <typename, typename> class Container>
size_t	MutantStack<T, Container>::size() const { return mutantStack.size(); }

template<typename T, template <typename, typename> class Container>
typename Container<T, std::allocator<T>>::iterator MutantStack<T, Container>::begin() { return mutantStack.begin(); }

template<typename T, template <typename, typename> class Container>
typename Container<T, std::allocator<T>>::iterator MutantStack<T, Container>::end() { return mutantStack.end(); }

template<typename T, template <typename, typename> class Container>
typename Container<T, std::allocator<T>>::iterator MutantStack<T, Container>::begin() const { return mutantStack.cbegin(); }

template<typename T, template <typename, typename> class Container>
typename Container<T, std::allocator<T>>::iterator MutantStack<T, Container>::end() const { return mutantStack.cend(); }