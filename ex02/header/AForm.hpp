/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:56:56 by strieste          #+#    #+#             */
/*   Updated: 2026/04/01 09:51:42 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(AForm const &copy);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		AForm&	operator=(AForm const &copy);
		void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		std::string const	&getName( void ) const;
		bool				getSigned( void ) const;
		int					getGradeToSignIt( void ) const;
		int					getGradeToExecuteIt( void ) const;

		class FormNotSignedException;

	protected:
		std::string const	_name;
		bool				_signed;
		int					_gradeToSignIt;
		int					_gradeToExecuteIt;

};

class AForm::FormNotSignedException: public std::exception
{
	public:
		const char	*what() const throw();
};

std::ostream	&operator<<(std::ostream &out, AForm const &copy);

#endif
