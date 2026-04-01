/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:21 by strieste          #+#    #+#             */
/*   Updated: 2026/04/01 10:01:54 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	std::srand(std::time(0));
	std::cout << " Test ShrubberyCreationForm " << std::endl;
	Bureaucrat  alice("Alice", 145);
	ShrubberyCreationForm shrubbery("home");
	std::cout << shrubbery;
	alice.signForm(shrubbery);
	alice.executeForm(shrubbery);
	std::cout << std::endl;

	std::cout << " Test ShrubberyCreationForm grade trop bas " << std::endl;
	Bureaucrat  junior("Junior", 150);
	ShrubberyCreationForm shrubbery2("garden");
	junior.signForm(shrubbery2);
	junior.executeForm(shrubbery2);
	std::cout << std::endl;

	std::cout << " Test ShrubberyCreationForm " << std::endl;
	Bureaucrat  Boss("Boss", 1);
	ShrubberyCreationForm shrubbery6("garden");
	Boss.signForm(shrubbery6);
	Boss.executeForm(shrubbery6);
	std::cout << std::endl;

	std::cout << " Test RobotomyRequestForm " << std::endl;
	Bureaucrat  bob("Bob", 45);
	RobotomyRequestForm robotomy("Charlie");
	std::cout << robotomy;
	bob.signForm(robotomy);
	bob.executeForm(robotomy);
	bob.executeForm(robotomy);
	bob.executeForm(robotomy);
	std::cout << std::endl;

	std::cout << " Test RobotomyRequestForm non signe " << std::endl;
	RobotomyRequestForm robotomy2("Dave");
	bob.executeForm(robotomy2);
	std::cout << std::endl;

	std::cout << " Test PresidentialPardonForm " << std::endl;
	Bureaucrat  president("President", 1);
	PresidentialPardonForm pardon("Bob");
	std::cout << pardon;
	president.signForm(pardon);
	president.executeForm(pardon);
	std::cout << std::endl;

	std::cout << " Test PresidentialPardonForm grade trop bas " << std::endl;
	Bureaucrat  nobody("Nobody", 26);
	PresidentialPardonForm pardon2("Alice");
	nobody.signForm(pardon2);
	nobody.executeForm(pardon2);
	std::cout << std::endl;

	std::cout << " Test execute sans signature " << std::endl;
	ShrubberyCreationForm shrubbery3("park");
	Bureaucrat  chad("Chad", 1);
	chad.executeForm(shrubbery3);
	std::cout << std::endl;

	return (0);
}