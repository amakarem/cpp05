/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:34:55 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 17:44:19 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
{
	this->name = "default";
	this->alreadysigned = false;
	this->sign_grade = 150;
	this->execute_grade = 150;
	std::cout << "Form void constructor called\n";
}

Form::Form(std::string _name, int _sign_grade, int _execute_grade)
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
	std::cout << "Form default constructor for " + _name + " called with sign grade:" << _sign_grade << " and execute grade:" << _execute_grade << "\n";
}
Form::~Form()
{
	std::cout << "Destructor for Form " + this->name + " called\n";
}
Form::Form(Form const &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}
Form &Form::operator=(Form const &cpy)
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

std::string Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->alreadysigned);
}

int	Form::getSignGrade() const
{
	return (this->sign_grade);
}

int	Form::getExecuteGrade() const
{
	return (this->execute_grade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	int his_grade = bureaucrat.getGrade();

	if (his_grade <= this->sign_grade)
		this->alreadysigned = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getSignGrade() << " ExecuteGrade: " << form.getExecuteGrade() << std::endl;
	return (os);
}
