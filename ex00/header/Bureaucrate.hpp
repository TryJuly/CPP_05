/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:43:06 by strieste          #+#    #+#             */
/*   Updated: 2026/03/15 14:26:32 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

# include <string>
# include <ostream>

class Bureaucrate
{
	public:
		Bureaucrate();
		Bureaucrate(std::string& name, unsigned int grade);
		Bureaucrate(Bureaucrate const &copy);
		~Bureaucrate();
		
		Bureaucrate&	operator=(Bureaucrate const &copy);
		std::string const	getName() const;
		unsigned int const	getGrade() const;
		friend std::ostream	&operator<<(std::ostream &out, Bureaucrate const &c);

	private:
		std::string const	_name;
		unsigned int	_grade;
};

#endif
