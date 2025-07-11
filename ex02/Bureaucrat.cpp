/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:34:55 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:45:51 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	this->name = "default";
	this->grade = 1;
	std::cout << "Bureaucrat void constructor called\n";
}

Bureaucrat::Bureaucrat(std::string _name, int _grade)
{
	this->name = _name;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	else
		this->grade = _grade;
	std::cout << "Bureaucrat default constructor for " + _name + " called with grade " << _grade << "\n";
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for Bureaucrat " + this->name + " called\n";
}
Bureaucrat::Bureaucrat(Bureaucrat const &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &cpy)
		return (*this);
	this->name = cpy.name;
	this->grade = cpy.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    else
        this->grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because ";
		if (this->grade > form.getSignGrade()) 
			std::cout << "his grade is " << this->grade << " and AForm require minimum " << form.getSignGrade() << " -";
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << this->name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because ";
		if (this->grade > form.getExecuteGrade()) 
			std::cout << "his grade is " << this->grade << " and Form require minimum " << form.getExecuteGrade() << " - ";
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << this->name << " executed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (os);
}
