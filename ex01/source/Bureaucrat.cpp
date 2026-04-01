/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:49:58 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 07:03:10 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() { return ; }
Bureaucrat::Bureaucrat(): _name("JuniorIT"), _grade(150) { return ; }
Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy.getName()), _grade(copy.getGrade()) { return ; }

int					Bureaucrat::getGrade() const { return (this->_grade); }
std::string const	&Bureaucrat::getName() const { return(this->_name); }
const char			*Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low !\n"; }
const char			*Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too High !\n"; }

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = grade;
	return ;
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
		this->_grade = copy.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &c)
{
	out << c.getName() << ", bureaucrate grade " << c.getGrade() << "." << std::endl;
	return (out);
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		if (form.getSigned() == false)
		{
			form.beSigned((*this));
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		else
			std::cout << form.getName() << " has already been signed !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName()
		<< " because " << e.what();
	}
	return ;
}
