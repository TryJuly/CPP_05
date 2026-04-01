/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:57:31 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 13:47:06 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(PresidentialPardonForm const &copy);
		// virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

		// virtual std::string const	&getName( void ) const;
		// virtual bool				getSigned( void ) const;
		// virtual int					getGradeToSignIt( void ) const;
		// virtual int					getGradeToExecuteIt( void ) const;

	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &copy);

#endif
