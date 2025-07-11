/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:55:09 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 20:22:50 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someIntern;

    std::cout << "\033[33m-- Testing Intern::makeForm --\033[0m\n\n";

    // Test 1: valid form names
    AForm* shrubbery = someIntern.makeForm("ShrubberyCreationForm", "Home");
    AForm* robotomy = someIntern.makeForm("RobotomyRequestForm", "Bender");
    AForm* presidential = someIntern.makeForm("PresidentialPardonForm", "Zaphod");

    // Test 2: invalid form name
    AForm* unknown = someIntern.makeForm("InvalidFormName", "Nowhere");

    std::cout << "\n\033[33m-- Testing Bureaucrat signing and executing forms --\033[0m\n\n";

    Bureaucrat bob("Bob", 1);       // High grade bureaucrat
    Bureaucrat alice("Alice", 150); // Low grade bureaucrat

    // Shrubbery test
    if (shrubbery) {
        std::cout << *shrubbery;
        bob.signForm(*shrubbery);
        bob.executeForm(*shrubbery);
        delete shrubbery;
    }

    std::cout << "\n";

    // Robotomy test
    if (robotomy) {
        std::cout << *robotomy;
        alice.signForm(*robotomy);   // Should fail signing (grade too low)
        bob.signForm(*robotomy);
        bob.executeForm(*robotomy);
        bob.executeForm(*robotomy);
        delete robotomy;
    }

    std::cout << "\n";

    // Presidential test
    if (presidential) {
        std::cout << *presidential;
        alice.signForm(*presidential); // Should fail signing (grade too low)
        bob.signForm(*presidential);
        alice.executeForm(*presidential); // Should fail executing (grade too low)
        bob.executeForm(*presidential);
        delete presidential;
    }

    std::cout << "\n";

    // Unknown form was never created
    if (unknown)
        delete unknown;

    return 0;
}
