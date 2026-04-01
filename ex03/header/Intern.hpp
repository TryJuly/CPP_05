/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:25:50 by strieste          #+#    #+#             */
/*   Updated: 2026/04/01 10:15:01 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();

		Intern&	operator=(Intern const &copy);
		AForm	*makeForm(std::string const nameForm, std::string const target);

		class	UnknowTypeFormException;

};

class	Intern::UnknowTypeFormException: public std::exception{
	public:
		const char	*what() const throw();
};

#endif