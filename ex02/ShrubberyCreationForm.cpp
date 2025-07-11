/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:10:21 by aelaaser          #+#    #+#             */
/*   Updated: 2025/07/11 19:27:06 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "default";
	std::cout << "ShrubberyCreationForm void constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = _target;
	std::cout << "ShrubberyCreationForm default constructor for " + _target + " called\n";
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor for ShrubberyCreationForm " + this->target + " called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &cpy)
		return (*this);
	this->target = cpy.target;
	return (*this);
}

void ShrubberyCreationForm::performAction() const
{
	std::ofstream outFile((this->target + std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "       _-_       \n";
		outFile << "    /~~   ~~\\    \n";
		outFile << " /~~         ~~\\ \n";
		outFile << "{               }\n";
		outFile << " \\  _-     -_  / \n";
		outFile << "   ~  \\\\ //  ~   \n";
		outFile << "_- -   | | _- _  \n";
		outFile << "  _ -  | |   -_  \n";
		outFile << "      // \\\\      \n";
		outFile << "      || ||      \n";
		outFile << "      || ||      \n";
		outFile << "      || ||      \n";
		outFile << "     _||_||_     \n";
		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileExeption();
}


const char *ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return ("Could not open and write the file!");
}
