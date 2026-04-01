/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:21 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 16:49:58 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/Intern.hpp"
#include <iostream>

int main(void)
{
	std::srand(std::time(0));

	std::cout << "--- Test creation des forms ---" << std::endl;
	Intern intern;
	AForm *shrubbery = intern.makeForm("shrubbery creation", "home");
	AForm *robotomy  = intern.makeForm("robotomy request", "Charlie");
	AForm *pardon    = intern.makeForm("presidential pardon", "Bob");
	std::cout << *shrubbery;
	std::cout << *robotomy;
	std::cout << *pardon;
	std::cout << std::endl;

	std::cout << "--- Test form introuvable ---" << std::endl;
	try {
		AForm *unknown = intern.makeForm("unknown form", "target");
		delete unknown;
	}
	catch (Intern::UnknowTypeFormException &e) {
		std::cerr << "Exception: " << e.what();
	}
	std::cout << std::endl;

	std::cout << "--- Test signer et executer shrubbery ---" << std::endl;
	Bureaucrat alice("Alice", 100);
	alice.signForm(*shrubbery);
	alice.executeForm(*shrubbery);
	std::cout << std::endl;

	std::cout << "--- Test signer et executer robotomy ---" << std::endl;
	Bureaucrat bob("Bob", 45);
	bob.signForm(*robotomy);
	bob.executeForm(*robotomy);
	bob.executeForm(*robotomy);
	bob.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << "--- Test signer et executer presidential ---" << std::endl;
	Bureaucrat president("President", 1);
	president.signForm(*pardon);
	president.executeForm(*pardon);
	std::cout << std::endl;

	std::cout << "--- Test grade trop bas pour signer ---" << std::endl;
	AForm *pardon2 = intern.makeForm("presidential pardon", "Alice");
	Bureaucrat nobody("Nobody", 150);
	nobody.signForm(*pardon2);
	nobody.executeForm(*pardon2);
	std::cout << std::endl;

	std::cout << "--- Test executer sans signer ---" << std::endl;
	AForm *robotomy2 = intern.makeForm("robotomy request", "Dave");
	Bureaucrat chad("Chad", 1);
	chad.executeForm(*robotomy2);
	std::cout << std::endl;

	std::cout << "--- Test copy constructor Intern ---" << std::endl;
	Intern intern2(intern);
	AForm *shrubbery2 = intern2.makeForm("shrubbery creation", "garden");
	std::cout << *shrubbery2;
	std::cout << std::endl;

	std::cout << "--- Nettoyage memoire ---" << std::endl;
	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete pardon2;
	delete robotomy2;
	delete shrubbery2;

	return (0);
}