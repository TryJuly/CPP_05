/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:29:08 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 13:46:41 by strieste         ###   ########.fr       */
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

		RobotomyRequestForm&	operator=(RobotomyRequestForm const &copy);
		// virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

		// virtual std::string const	&getName( void ) const;
		// virtual bool				getSigned( void ) const;
		// virtual int					getGradeToSignIt( void ) const;
		// virtual int					getGradeToExecuteIt( void ) const;
	
	private:
		std::string	_target;

};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &copy);

#endif