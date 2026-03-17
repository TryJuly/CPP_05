/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:56:56 by strieste          #+#    #+#             */
/*   Updated: 2026/03/17 14:06:25 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

// class Bureaucrat;

class AForm
{
	public:
		Form();
		Form(Form const &copy);
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned);
		virtual ~Form();

		Form&	operator=(Form const &copy);
		virtual void	beSigned(Bureaucrat const &bureaucrat) = 0;
		

		virtual std::string const	&getName( void ) const = 0;
		virtual bool const			&getSigned( void ) const = 0;
		virtual unsigned const int	&getGradeToSignIt( void ) const = 0;
		virtual unsigned const int	&getGradeToExecuteIt( void ) const = 0;

	private:
		std::string const	_name;
		bool				_signed;
		unsigned const int	_gradeToSignIt;
		unsigned const int	_gradeToExecuteIt;

};

std::ostream	&operator<<(std::ostream &out, Form const &copy);

#endif
