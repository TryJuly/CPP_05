/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:25:50 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 16:55:47 by strieste         ###   ########.fr       */
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
		AForm	*makeForm(const std::string nameForm, const std::string target);
		
		class	UnknowTypeFormException;

	// private:
	// 	static std::string	_formNames[3];
	// 	static AForm*	(*_formCreate[3])(std::string target);

};

class	Intern::UnknowTypeFormException: public std::exception{
	public:
		const char	*what() const throw();
};

// static AForm	*createShrubberyForm(const std::string target);
// static AForm	*createPresidentialPardonForm(const std::string target);
// static AForm	*createRobotomyRequestForm(const std::string target);

#endif