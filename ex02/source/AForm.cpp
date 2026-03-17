/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:02:51 by strieste          #+#    #+#             */
/*   Updated: 2026/03/17 14:17:10 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"

AForm::~AForm() { return ; }
AForm::AForm():
_name("Contract"), _signed(false), _gradeToSignIt(50), _gradeToExecuteIt(50)
{ return ; }

bool const			&AForm::getSigned( void ) const { return (this->_signed); }
std::string const	&AForm::getName( void ) const { return (this->_name); }
unsigned const int	&AForm::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
unsigned const int	&AForm::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

// AForm::AForm(AForm const &copy):
// _name(copy._name), _signed(copy._signed), _gradeToSignIt(copy._gradeToSignIt), _gradeToExecuteIt(copy._gradeToExecuteIt)
// { return ; }

// AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute):
// _name(name), _signed(false), _gradeToSignIt(gradeToSign), _gradeToExecuteIt(gradeToExecute)
// { return ; }

// AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned):
// _name(name), _signed(isSigned), _gradeToSignIt(gradeToSign), _gradeToExecuteIt(gradeToExecute)
// { return ; }

// AForm&	AForm::operator=(AForm const &copy)
// {
// 	if (this != &copy)
// 		this->_signed = copy._signed;
// 	return (*this);
// }

// std::ostream	&operator<<(std::ostream &out, AForm const &copy)
// {
// 	out << copy.getName() << " required grade to sign it: " << copy.getGradeToSignIt();
// 	out << ", required grade to execute: " << copy.getGradeToExecuteIt();
// 	out << ", this form is signed: " << copy.getSigned() << std::endl;
// 	return (out);
// }

// void	AForm::beSigned(Bureaucrat const &bureaucrat)
// {
// 	if (bureaucrat.getGrade() > this->getGradeToSignIt())
// 		throw (Bureaucrat::GradeTooLowException());
// 	this->_signed = true;
// 	return ;
// }
