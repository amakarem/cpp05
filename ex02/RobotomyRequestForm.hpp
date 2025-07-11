/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:41:36 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:07:48 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		virtual void	performAction() const;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm();

		class RobotomyRequestFormFaild : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
