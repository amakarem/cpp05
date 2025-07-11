/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:11:04 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:34:40 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	name;
		bool alreadysigned;
		int	sign_grade;
		int execute_grade;
		virtual void	performAction() const = 0;
	public:
		AForm(void);
		AForm(std::string	_name, int _sign_grade, int _execute_grade);
		virtual ~AForm();
		AForm(AForm const &cpy);
		AForm &operator = (AForm const &cpy);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void 		beSigned(Bureaucrat const & bureaucrat);
		void		execute(Bureaucrat const & executor) const;

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

		class FormIsNotSigned : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &os, AForm const &other);

#endif