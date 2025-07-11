/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:34:48 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 17:48:21 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	protected:
		std::string	name;
		int	grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string	_name, int _grade);
		virtual ~Bureaucrat();
		Bureaucrat(Bureaucrat const &cpy);
		Bureaucrat &operator = (Bureaucrat const &cpy);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &other);

#endif