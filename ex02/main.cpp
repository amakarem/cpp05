/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:55:09 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:24:57 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    // Seed randomness once
    std::srand(std::time(nullptr));

    std::cout << "\033[33mTest ex02 - Form and Bureaucrat interaction\033[0m\n\n";

    // --- Test ShrubberyCreationForm ---
    std::cout << "\033[33m\n-- Test ShrubberyCreationForm --\033[0m\n";
    Bureaucrat Mr_Shrubby("Mr_Shrubby", 130);
    ShrubberyCreationForm Shrubby_form("Hello");

    std::cout << "\nInitial form status:\n" << Shrubby_form;
    Mr_Shrubby.signForm(Shrubby_form);
    std::cout << "After signing:\n" << Shrubby_form;
    Mr_Shrubby.executeForm(Shrubby_form);

    // --- Test RobotomyRequestForm ---
    std::cout << "\033[33m\n-- Test RobotomyRequestForm --\033[0m\n";
    RobotomyRequestForm Robo_form("I am a robo form");
    Bureaucrat Mr_Robo("Mr_Robo", 45);

    // Trying to execute unsigned form (should fail)
    Mr_Robo.executeForm(Robo_form);

    // Signing the form
    Mr_Robo.signForm(Robo_form);

    // Multiple execution attempts to see random success/failures
    for (int i = 0; i < 4; ++i)
        Mr_Robo.executeForm(Robo_form);

    // --- Test PresidentialPardonForm ---
    std::cout << "\033[33m\n-- Test PresidentialPardonForm --\033[0m\n";
    PresidentialPardonForm President_form("I am a robo form");
    Bureaucrat Mr_President("Mr_President", 5);

    // Mr_Robo tries to execute and sign (should fail due to grade)
    Mr_Robo.executeForm(President_form);
    Mr_Robo.signForm(President_form);

    // Mr_President signs and executes
    Mr_President.signForm(President_form);
    Mr_President.executeForm(President_form);

    // Execute again to confirm consistent behavior
    Mr_President.executeForm(President_form);

    return 0;
}
