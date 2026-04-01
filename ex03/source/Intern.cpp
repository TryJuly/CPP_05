/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:56:10 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 17:03:42 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

Intern::Intern()
{ return ; }

Intern::Intern(Intern const &copy)
{
	*this = copy;
	return ;
}

Intern::~Intern()
{ return ; }

Intern&	Intern::operator=(Intern const &copy)
{
	(void)copy;
	return (*this);
}

static AForm	*createShrubberyForm(const std::string target)
{ return (new ShrubberyCreationForm(target)); }

static AForm	*createPresidentialPardonForm(const std::string target)
{ return (new PresidentialPardonForm(target)); }
static AForm	*createRobotomyRequestForm(const std::string target)
{ return (new RobotomyRequestForm(target)); }

const char	*Intern::UnknowTypeFormException::what() const throw()
{ return ("Form type unknown by intern."); }

AForm	*Intern::makeForm(const std::string nameForm, const std::string target)
{
	AForm*	(*_formCreate[3])(std::string target) = {&createRobotomyRequestForm, &createPresidentialPardonForm, &createShrubberyForm};
	std::string nameCreateForm[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (nameCreateForm[i] == nameForm)
		{
			std::cout << "Intern creates " << nameCreateForm[i] << std::endl;
			return (_formCreate[i](target));
		}
	}
	throw (Intern::UnknowTypeFormException());
	std::cout << "Form: " << nameForm << " unknown by intern. " << std::endl;
	return (nullptr);
}
