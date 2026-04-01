/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:56:56 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 07:10:26 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(Form const &copy);
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		// Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, bool isSigned);
		~Form();

		Form&	operator=(Form const &copy);
		void	beSigned(Bureaucrat const &bureaucrat);
		

		std::string const	&getName( void ) const;
		bool				getSigned( void ) const;
		int					getGradeToSignIt( void ) const;
		int					getGradeToExecuteIt( void ) const;

	private:
		std::string const	_name;
		bool				_signed;
		int					_gradeToSignIt;
		int					_gradeToExecuteIt;

};

std::ostream	&operator<<(std::ostream &out, Form const &copy);

#endif
