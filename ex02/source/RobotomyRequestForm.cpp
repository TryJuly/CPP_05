/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:41:56 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 14:23:50 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RobotomyRequestForm.hpp"

// std::string const	&RobotomyRequestForm::getName( void ) const { return (this->_name); }
// bool				RobotomyRequestForm::getSigned( void ) const { return (this->_signed); }
// int					RobotomyRequestForm::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
// int					RobotomyRequestForm::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", 72, 45), _target("default")
{ return ; }

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
AForm("RobotomyRequestForm", 72, 45), _target(target)
{ return ; }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):
AForm(copy), _target(copy._target)
{ return ; }

RobotomyRequestForm::~RobotomyRequestForm()
{ return ; }

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	if (this != &copy)
		this->_target = copy._target;
	return (*this);
}

// void	RobotomyRequestForm::beSigned(Bureaucrat const &bureaucrat)
// {
// 	if (bureaucrat.getGrade() > this->getGradeToSignIt())
// 		throw (Bureaucrat::GradeTooLowException());
// 	this->_signed = true;
// 	return ;
// }

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecuteIt())
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Bruuuuuuuuuuuuhhhh !!!!!" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &copy)
{
	out << copy.getName() << " required grade to sign it: " << copy.getGradeToSignIt();
	out << ", required grade to execute: " << copy.getGradeToExecuteIt();
	out << ", this form is signed: " << copy.getSigned() << std::endl;
	return (out);
}