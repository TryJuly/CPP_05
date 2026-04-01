/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:30:05 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 07:34:34 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &copy);
		// virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

		// virtual std::string const	&getName( void ) const;
		// virtual bool				getSigned( void ) const;
		// virtual int					getGradeToSignIt( void ) const;
		// virtual int					getGradeToExecuteIt( void ) const;
	private:
		std::string	_target;

};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &copy);

#endif