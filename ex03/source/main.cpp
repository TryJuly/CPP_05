/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:21 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 11:54:47 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"

int	main(void)
{
	std::string	name = "Boss";
	std::string	nameForm1 = "Form1";
	std::string	nameForm2 = "Form2";
	std::string	nameForm3 = "Form3";

	AForm	*facture1 = new RobotomyRequestForm(nameForm1);
	AForm	*facture2 = new ShrubberyCreationForm(nameForm2);
	AForm	*facture3 = new PresidentialPardonForm(nameForm3);

	Bureaucrat	boss(name, 51);

	std::cout << std::endl;
	std::cout << *facture1;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.executeForm(*facture1);
	std::cout << std::endl;
	std::cout << *facture1;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.executeForm(*facture1);
	std::cout << std::endl;
	std::cout << *facture2;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.executeForm(*facture2);
	std::cout << std::endl;
	std::cout << *facture3;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.executeForm(*facture3);

	return (0);
}