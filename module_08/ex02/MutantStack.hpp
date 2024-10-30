/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:58:18 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/30 12:18:18 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class MutantStack
{
public:
	MutantStack();
	MutantStack(const MutantStack& copy);
	const MutantStack&	operator=(const MutantStack& other);
	~MutantStack();
	
};


top -> accesses the top element


empty -> checks whether the container adaptor is empt

size -> returns the number of elements

push -> inserts element at the top

push_range -> inserts a range of elements at the top

emplace -> constructs element in-place at the top

pop -> removes the top element

swap -> swaps the contents
