/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:02:51 by strieste          #+#    #+#             */
/*   Updated: 2026/04/01 09:52:03 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"

AForm::~AForm() { return ; }
AForm::AForm():
_name("Contract"), _signed(false), _gradeToSignIt(50), _gradeToExecuteIt(50)
{ return ; }

bool				AForm::getSigned( void ) const { return (this->_signed); }
std::string const	&AForm::getName( void ) const { return (this->_name); }
int					AForm::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
int					AForm::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

const char	*AForm::FormNotSignedException::what() const throw()
{ return ("This form is not signed !\n"); }

AForm::AForm(AForm const &copy):
_name(copy._name), _signed(copy._signed), _gradeToSignIt(copy._gradeToSignIt), _gradeToExecuteIt(copy._gradeToExecuteIt)
{ return ; }

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):
_name(name), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_gradeToSignIt = gradeToSign;
	this->_gradeToExecuteIt = gradeToExecute;
	return ; 
}

AForm&	AForm::operator=(AForm const &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, AForm const &copy)
{
	out << copy.getName() << " required grade to sign it: " << copy.getGradeToSignIt();
	out << ", required grade to execute: " << copy.getGradeToExecuteIt();
	out << ", this form is signed: " << copy.getSigned() << std::endl;
	return (out);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSignIt())
		throw (Bureaucrat::GradeTooLowException());
	this->_signed = true;
	return ;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
	{
		if (executor.getGrade() > this->_gradeToExecuteIt)
			throw (Bureaucrat::GradeTooLowException());
	}
	return ;
}
