/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:30:05 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 11:38:04 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		virtual ~ShrubberyCreationForm();

		virtual ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &copy);
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

		virtual std::string const	&getName( void ) const;
		virtual bool const			&getSigned( void ) const;
		virtual unsigned const int	&getGradeToSignIt( void ) const;
		virtual unsigned const int	&getGradeToExecuteIt( void ) const;

};

#endif