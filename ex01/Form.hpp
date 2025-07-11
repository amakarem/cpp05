/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:34:48 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 15:53:21 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	name;
		bool alreadysigned;
		int	sign_grade;
		int execute_grade;
	public:
		Form(void);
		Form(std::string	_name, int _sign_grade, int _execute_grade);
		virtual ~Form();
		Form(Form const &cpy);
		Form &operator = (Form const &cpy);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void 		beSigned(const Bureaucrat &bureaucrat);

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
std::ostream &operator<<(std::ostream &os, Form const &other);

#endif