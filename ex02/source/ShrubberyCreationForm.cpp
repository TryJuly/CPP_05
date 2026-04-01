/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:02:28 by strieste          #+#    #+#             */
/*   Updated: 2026/04/01 13:08:08 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("Radom_shrubbery", 145, 137), _target("Default")
{ return ; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{ return ; }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy):
AForm(copy), _target(copy._target)
{ return ; }

ShrubberyCreationForm::~ShrubberyCreationForm()
{ return ; }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this != &copy)
		this->_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecuteIt())
		throw (Bureaucrat::GradeTooLowException());
	std::ofstream	fd((this->_target + "_shrubbery").c_str());
	if (!fd.is_open()) {
		std::cerr << "Error creating file." << std::endl;
		return ;
	}
	fd << "          *           " << std::endl;
	fd << "         ***          " << std::endl;
	fd << "        *****         " << std::endl;
	fd << "       *******        " << std::endl;
	fd << "      *********       " << std::endl;
	fd << "     ***********      " << std::endl;
	fd << "    *************     " << std::endl;
	fd << "   ***************    " << std::endl;
	fd << "  *****************   " << std::endl;
	fd << "          |           " << std::endl;
	fd.close();
	return ;
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &copy)
{
	out << copy.getName() << " required grade to sign it: " << copy.getGradeToSignIt();
	out << ", required grade to execute: " << copy.getGradeToExecuteIt();
	out << ", this form is signed: " << copy.getSigned() << std::endl;
	return (out);
}
