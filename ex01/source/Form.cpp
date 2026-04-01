/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:02:51 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 07:09:48 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Form.hpp"

Form::~Form() { return ; }
Form::Form():
_name("Contract"), _signed(false), _gradeToSignIt(50), _gradeToExecuteIt(50)
{ return ; }

std::string const	&Form::getName( void ) const { return (this->_name); }
bool				Form::getSigned( void ) const { return (this->_signed); }
int					Form::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
int					Form::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

Form::Form(Form const &copy):
_name(copy._name), _signed(copy._signed), _gradeToSignIt(copy._gradeToSignIt), _gradeToExecuteIt(copy._gradeToExecuteIt)
{ return ; }

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
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

// Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned):
// _name(name), _signed(isSigned), _gradeToSignIt(gradeToSign), _gradeToExecuteIt(gradeToExecute)
// { return ; }

Form&	Form::operator=(Form const &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Form const &copy)
{
	out << copy.getName() << " required grade to sign it: " << copy.getGradeToSignIt();
	out << ", required grade to execute: " << copy.getGradeToExecuteIt();
	out << ", this form is signed: " << copy.getSigned() << std::endl;
	return (out);
}


void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSignIt())
		throw (Bureaucrat::GradeTooLowException());
	this->_signed = true;
	return ;
}
