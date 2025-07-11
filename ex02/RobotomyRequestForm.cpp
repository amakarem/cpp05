/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:10:21 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:26:55 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 145, 137)
{
	this->target = "default";
	std::cout << "RobotomyRequestForm void constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 145, 137)
{
	this->target = _target;
	std::cout << "RobotomyRequestForm default constructor for " + _target + " called\n";
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor for RobotomyRequestForm " + this->target + " called\n";
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &cpy)
		return (*this);
	this->target = cpy.target;
	return (*this);
}

static int roboto_fail = 0;

void RobotomyRequestForm::performAction() const
{
	std::cout << "Bzzzz... bzzzz... vrrrrr... drilling noises...\n";
	if (roboto_fail++ % 2)
        std::cout << "Beeep Be Be Beeeee Beeeeeeeep. " << this->target << " has been robotomized successfully!" << std::endl;
    else
        throw RobotomyRequestFormFaild();
}


const char *RobotomyRequestForm::RobotomyRequestFormFaild::what() const throw()
{
	return ("robotomy failed.");
}
