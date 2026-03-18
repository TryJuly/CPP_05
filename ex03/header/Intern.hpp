/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:35:17 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 13:49:49 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern();
		~Intern();

		Intern&	operator=(Intern const &copy);
		AForm&	makeForm(std::string const &nameForm, std::string const &target);
};

#endif