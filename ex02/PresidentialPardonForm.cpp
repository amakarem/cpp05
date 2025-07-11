/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:10:21 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:26:14 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5)
{
	this->target = "default";
	std::cout << "PresidentialPardonForm void constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentialPardonForm", 25, 5)
{
	this->target = _target;
	std::cout << "PresidentialPardonForm default constructor for " + _target + " called\n";
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor for PresidentialPardonForm " + this->target + " called\n";
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &cpy)
		return (*this);
	this->target = cpy.target;
	return (*this);
}

void PresidentialPardonForm::performAction() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
