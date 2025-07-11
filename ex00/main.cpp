/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:55:09 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 17:09:23 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\033[33mTest ex00\033[0m\n\n";
	std::cout << "\033[33mTesting invalid grade creations\033[0m\n";
	try
	{
		Bureaucrat tooLow("Bernd", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception for too low grade: " << e.what() << "\n";
	}
	try
	{
		Bureaucrat tooHigh("Olaf", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception for too high grade: " << e.what() << "\n";
	}
	std::cout << "\n\033[33mTesting increment at boundaries\033[0m\n";
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.incrementGrade();
		std::cout << "After increment: " << bob;
		bob.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught on increment: " << e.what() << "\n";
	}
	std::cout << bob;
	std::cout << "\n\033[33mTesting decrement at boundaries\033[0m\n";
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.decrementGrade();
		std::cout << "After decrement: " << tim;
		tim.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught on decrement: " << e.what() << "\n";
	}
	std::cout << tim;
	std::cout << "\n\033[33mTesting normal increments/decrements\033[0m\n";
	Bureaucrat alice("Alice", 100);
	std::cout << alice;
	alice.incrementGrade();
	std::cout << "After increment: " << alice;
	alice.decrementGrade();
	std::cout << "After decrement: " << alice;
	return (0);
}
