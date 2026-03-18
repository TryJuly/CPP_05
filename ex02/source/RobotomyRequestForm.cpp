/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:41:56 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 12:09:30 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RobotomyRequestForm.hpp"

std::string const	&RobotomyRequestForm::getName( void ) const { return (this->_name); }
bool const			&RobotomyRequestForm::getSigned( void ) const { return (this->_signed); }
unsigned const int	&RobotomyRequestForm::getGradeToSignIt( void ) const { return (this->_gradeToSignIt); }
unsigned const int	&RobotomyRequestForm::getGradeToExecuteIt( void ) const { return (this->_gradeToExecuteIt); }

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", 72, 45)
{ return ; }

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
AForm("RobotomyRequestForm", 72, 45)
{
	std::srand(std::time(0));
	int	value = std::rand() % 2;
	std::cout << "Bruuuuuuuuuuuuuuuuhhhhhhhh !!!!" << std::endl;
	if (value == 0)
		std::cout << target << " has been robotomized !" << std::endl;
	else
		std::cout << target << " robotomy failed !" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
	this->_signed = copy._signed;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{ return ; }

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

void	RobotomyRequestForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSignIt())
		throw (Bureaucrat::GradeTooLowException());
	this->_signed = true;
	return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
	{
		if (executor.getGrade() > this->_gradeToExecuteIt)
			throw (Bureaucrat::GradeTooLowException());
	}
	return ;
}