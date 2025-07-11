/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:55:09 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 16:00:48 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\033[33mTest ex01\033[0m\n\n";

    // Test invalid grades on creation
    std::cout << "\033[33mTesting invalid grade creations\033[0m\n";
    try {
        Bureaucrat tooLow("Bernd", 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception for too low grade: " << e.what() << "\n";
    }

    try {
        Bureaucrat tooHigh("Olaf", 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception for too high grade: " << e.what() << "\n";
    }

    // Test incrementing grade at boundary
    std::cout << "\n\033[33mTesting increment at boundaries\033[0m\n";
    Bureaucrat bob("Bob", 2);
    std::cout << bob;

    try {
        bob.incrementGrade();
        std::cout << "After increment: " << bob;
        bob.incrementGrade();  // This should throw (grade goes to 0)
    } catch (const std::exception& e) {
        std::cerr << "Exception caught on increment: " << e.what() << "\n";
    }

    std::cout << bob;

    // Test decrementing grade at boundary
    std::cout << "\n\033[33mTesting decrement at boundaries\033[0m\n";
    Bureaucrat tim("Tim", 149);
    std::cout << tim;

    try {
        tim.decrementGrade();
        std::cout << "After decrement: " << tim;
        tim.decrementGrade();  // This should throw (grade goes to 151)
    } catch (const std::exception& e) {
        std::cerr << "Exception caught on decrement: " << e.what() << "\n";
    }

    std::cout << tim;

    // Test normal increment/decrement
    std::cout << "\n\033[33mTesting normal increments/decrements\033[0m\n";
    Bureaucrat alice("Alice", 100);
    std::cout << alice;
    alice.incrementGrade();
    std::cout << "After increment: " << alice;
    alice.decrementGrade();
    std::cout << "After decrement: " << alice;

    return 0;
}

