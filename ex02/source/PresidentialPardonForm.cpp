/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:12:28 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 14:15:32 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PresidentialPardonForm.hpp"

// std::string const	&PresidentialPardonForm::getName( void ) const { return (this->_name); }
// bool				PresidentialPardonForm::getSigned( void ) const { return (this->_signed); }
// int					PresidentialPardonForm::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
// int					PresidentialPardonForm::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", 25, 5), _target("Default")
{ return ; }

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
AForm("PresidentialPardonForm", 25, 5), _target(target)
{ return ; }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):
AForm(copy), _target(copy._target)
{ return ; }

PresidentialPardonForm::~PresidentialPardonForm()
{ return ; }

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	if (this != &copy)
		this->_target = copy._target;
	return (*this);
}

// void	PresidentialPardonForm::beSigned(Bureaucrat const &bureaucrat)
// {
// 	if (bureaucrat.getGrade() > this->getGradeToSignIt())
// 		throw (Bureaucrat::GradeTooLowException());
// 	this->_signed = true;
// 	return ;
// }

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_gradeToExecuteIt)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << _target << " you are pardoned by Zarphod Beeblebrox." << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &copy)
{
	out << copy.getName() << " required grade to sign it: " << copy.getGradeToSignIt();
	out << ", required grade to execute: " << copy.getGradeToExecuteIt();
	out << ", this form is signed: " << copy.getSigned() << std::endl;
	return (out);
}