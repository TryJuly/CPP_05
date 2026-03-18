/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:56:56 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 11:37:50 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(AForm const &copy);
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned);
		virtual ~AForm();

		virtual AForm&	operator=(AForm const &copy);
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		virtual std::string const	&getName( void ) const;
		virtual bool const			&getSigned( void ) const;
		virtual unsigned const int	&getGradeToSignIt( void ) const;
		virtual unsigned const int	&getGradeToExecuteIt( void ) const;

	protected:
		std::string const	_name;
		bool				_signed;
		unsigned const int	_gradeToSignIt;
		unsigned const int	_gradeToExecuteIt;

};

std::ostream	&operator<<(std::ostream &out, AForm const &copy);

#endif
