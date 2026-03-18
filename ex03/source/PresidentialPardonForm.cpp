/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:12:28 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 11:39:27 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PresidentialPardonForm.hpp"

std::string const	&PresidentialPardonForm::getName( void ) const { return (this->_name); }
bool const			&PresidentialPardonForm::getSigned( void ) const { return (this->_signed); }
unsigned const int	&PresidentialPardonForm::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
unsigned const int	&PresidentialPardonForm::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", 25, 5)
{ return ; }

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << target << " you are pardoned by Zarphod Beeblebrox." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
	this->_signed = copy._signed;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{ return ; }

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

void	PresidentialPardonForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSignIt())
		throw (Bureaucrat::GradeTooLowException());
	this->_signed = true;
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
	{
		if (executor.getGrade() > this->_gradeToExecuteIt)
			throw (Bureaucrat::GradeTooLowException());
	}
	return ;
}
