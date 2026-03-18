/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:57:31 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 11:37:57 by strieste         ###   ########.fr       */
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

		virtual PresidentialPardonForm&	operator=(PresidentialPardonForm const &copy);
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

		virtual std::string const	&getName( void ) const;
		virtual bool const			&getSigned( void ) const;
		virtual unsigned const int	&getGradeToSignIt( void ) const;
		virtual unsigned const int	&getGradeToExecuteIt( void ) const;

};

#endif
