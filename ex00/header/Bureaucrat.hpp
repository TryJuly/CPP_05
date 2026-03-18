/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:43:06 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 09:41:01 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string& name, unsigned int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat&	operator=(Bureaucrat const &copy);
		void	increment( void );
		void	decrement( void );
		friend std::ostream	&operator<<(std::ostream &out, Bureaucrat const &c);

		std::string const	&getName() const;
		unsigned int const	&getGrade() const;

		class	GradeTooHighException: public std::exception{
			public:
				const char	*what() const throw();
		};
		class	GradeTooLowException: public std::exception{
			public:
				const char	*what() const throw();
		};

	private:
		std::string const	_name;
		unsigned int	_grade;
		
};

#endif
