/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:02:28 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 12:01:21 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ShrubberyCreationForm.hpp"

std::string const	&ShrubberyCreationForm::getName( void ) const { return (this->_name); }
bool const			&ShrubberyCreationForm::getSigned( void ) const { return (this->_signed); }
unsigned const int	&ShrubberyCreationForm::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
unsigned const int	&ShrubberyCreationForm::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("Radom_shrubbery", 145, 137)
{ return ; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
AForm("ShrubberyCreationForm", 145, 137)
{
	std::string fileName = target + "shrubbery";
	std::ofstream	fd(fileName.c_str());
	if (!fd.is_open())
	{
		std::cerr << "Error create " << target << " file." << std::endl;
		return ;
	}
	fd << "ASCII trees";
	fd.close();
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
	this->_signed = copy._signed;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ return ; }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSignIt())
		throw (Bureaucrat::GradeTooLowException());
	this->_signed = true;
	return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
	{
		if (executor.getGrade() > this->_gradeToExecuteIt)
			throw (Bureaucrat::GradeTooLowException());
	}
	return ;
}
