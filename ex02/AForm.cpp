/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:10:21 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:34:47 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
{
	this->name = "default";
	this->alreadysigned = false;
	this->sign_grade = 150;
	this->execute_grade = 150;
	std::cout << "AForm void constructor called\n";
}

AForm::AForm(std::string _name, int _sign_grade, int _execute_grade)
{
	this->name = _name;
	if (_sign_grade < 1 || _execute_grade < 1)
		throw GradeTooHighException();
	else if (_sign_grade > 150 || _execute_grade > 150)
		throw GradeTooLowException();
	else {
		this->sign_grade = _sign_grade;
		this->execute_grade = _execute_grade;
	}
	std::cout << "AForm default constructor for " + _name + " called with sign grade:" << _sign_grade << " and execute grade:" << _execute_grade << "\n";
}
AForm::~AForm()
{
	std::cout << "Destructor for AForm " + this->name + " called\n";
}
AForm::AForm(AForm const &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}
AForm &AForm::operator=(AForm const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &cpy)
		return (*this);
	this->name = cpy.name;
	this->alreadysigned = cpy.alreadysigned;
	this->sign_grade = cpy.sign_grade;
	this->execute_grade = cpy.execute_grade;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->alreadysigned);
}

int	AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int	AForm::getExecuteGrade() const
{
	return (this->execute_grade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	int his_grade = bureaucrat.getGrade();

	if (his_grade <= this->sign_grade)
		this->alreadysigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(const Bureaucrat &executor) const
{
	int his_grade = executor.getGrade();

	if (!this->alreadysigned)
		throw FormIsNotSigned();
	else if (his_grade <= this->execute_grade)
		performAction();
	else
		throw GradeTooLowException();
}
void	formAction()
{
	
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}
const char *AForm::FormIsNotSigned::what() const throw()
{
	return ("Form can not be executed, because it is not signed!");
}

std::ostream &operator<<(std::ostream &os,  AForm const &AForm)
{
	os << "Name: " << AForm.getName() << " isSigned: " << AForm.getIsSigned() << " SignGrade: " << AForm.getSignGrade() << " ExecuteGrade: " << AForm.getExecuteGrade() << std::endl;
	return (os);
}
