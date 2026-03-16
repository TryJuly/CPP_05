/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:49:58 by strieste          #+#    #+#             */
/*   Updated: 2026/03/15 14:27:46 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

Bureaucrate::Bureaucrate(): _name("JuniorIT"), _grade(150) {}
Bureaucrate::Bureaucrate(std::string& name, unsigned int grade): _name(name), _grade(grade) {}
Bureaucrate::Bureaucrate(Bureaucrate const &copy): _name(copy.getName()), _grade(copy.getGrade()) {}
Bureaucrate::~Bureaucrate() {}
std::string const Bureaucrate::getName() const { return(this->_name); }
unsigned const int Bureaucrate::getGrade() const { return (this->_grade); }

Bureaucrate&	Bureaucrate::operator=(Bureaucrate const &copy)
{
	if (this != &copy)
		this->_grade = copy.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrate const &c)
{
	out << c.getName() << " , bureaucrate grade " << c.getGrade() << ".";
	return (out);
}
