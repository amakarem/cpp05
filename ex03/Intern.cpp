/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:50:57 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 20:25:39 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{

}
Intern::~Intern()
{
	std::cout << "Destructor for Intern called\n";
}
Intern::Intern(Intern const &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}
Intern &Intern::operator=(Intern const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &cpy)
		return *this;
	return (*this);
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}


AForm *Intern::makeForm(const std::string form_to_create, const std::string form_target)
{
	AForm *(*formsLink[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for(int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i]) {
			std::cout << "Intern creates " << form_to_create << " now" << std::endl;
			return (formsLink[i](form_target));
		}

	}
    std::cout << "\033[33mIntern cannot create a form " << form_to_create << " as Form is not exist\033[0m" << std::endl;
    return nullptr;
}
