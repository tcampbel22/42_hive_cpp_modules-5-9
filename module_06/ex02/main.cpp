/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:11:25 by tcampbel          #+#    #+#             */
/*   Updated: 2024/10/24 11:25:37 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	try
	{
		Base *base = generate();
		Base& baseRef = *base;
		identify(base);
		identify(baseRef);
		delete base;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n'; 
	}
}