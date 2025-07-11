/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:55:09 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 17:47:04 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\033[33mTest ex01 - Form and Bureaucrat interaction\033[0m\n\n";

    std::cout << "\033[33mTesting invalid form creations\033[0m\n";
    try
    {
        Form invalidLow("InvalidLow", 0, 50); // sign grade too high (0)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception for too high sign grade: " << e.what() << "\n";
    }

    try
    {
        Form invalidHigh("InvalidHigh", 151, 50); // sign grade too low (151)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception for too low sign grade: " << e.what() << "\n";
    }

    std::cout << "\n\033[33mTesting signing forms with insufficient and sufficient grades\033[0m\n";

    Bureaucrat bob("Bob", 50);
    Form formA("FormA", 45, 100);

    std::cout << bob << std::endl;
    std::cout << formA << std::endl;

    try
    {
        bob.signForm(formA);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Bob failed to sign FormA: " << e.what() << "\n";
    }

    Bureaucrat alice("Alice", 40);
    std::cout << alice << std::endl;

    try
    {
        alice.signForm(formA);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Alice failed to sign FormA: " << e.what() << "\n";
    }

    std::cout << formA << std::endl;

    std::cout << "\n\033[33mTesting repeated signing attempts\033[0m\n";
    try
    {
        alice.signForm(formA); // should already be signed
    }
    catch (const std::exception &e)
    {
        std::cerr << "Alice failed to sign FormA again: " << e.what() << "\n";
    }

    return 0;
}

