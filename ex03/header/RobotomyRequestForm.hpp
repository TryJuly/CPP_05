/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:29:08 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 12:06:38 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		virtual ~RobotomyRequestForm();

		virtual RobotomyRequestForm&	operator=(RobotomyRequestForm const &copy);
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

		virtual std::string const	&getName( void ) const;
		virtual bool const			&getSigned( void ) const;
		virtual unsigned const int	&getGradeToSignIt( void ) const;
		virtual unsigned const int	&getGradeToExecuteIt( void ) const;

};

#endif