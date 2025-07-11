/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:50:54 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 20:09:14 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	AForm;

class Intern
{
  public:
	Intern(void);
	virtual ~Intern();
	Intern(Intern const &cpy);
	Intern &operator=(Intern const &cpy);

	AForm *makeForm(const std::string form_to_create, const std::string form_target);
};

#endif