/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:21 by strieste          #+#    #+#             */
/*   Updated: 2026/04/01 09:41:38 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include <string>
#include <iostream>

int main()
{

	std::cout << " Test constructeur valide " << std::endl;
	Bureaucrat alice("Alice", 50);
	std::cout << alice << std::endl;

	std::cout << "\n Test constructeur grade too high " << std::endl;
	try {
		Bureaucrat bad("Bad", 0);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test constructeur grade too low " << std::endl;
	try {
		Bureaucrat bad("Bad", 151);
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test incrementGrade " << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob << std::endl;
	bob.incrementGrade();
	std::cout << bob << std::endl;

	std::cout << "\n Test incrementGrade depasse " << std::endl;
	try {
		bob.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test decrementGrade " << std::endl;
	Bureaucrat charlie("Charlie", 149);
	std::cout << charlie << std::endl;
	charlie.decrementGrade();
	std::cout << charlie << std::endl;

	std::cout << "\n Test decrementGrade depasse " << std::endl;
	try {
		charlie.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n Test copy constructor " << std::endl;
	Bureaucrat alice2(alice);
	std::cout << alice2 << std::endl;

	std::cout << "\n Test operator= " << std::endl;
	Bureaucrat alice3("Temp", 100);
	alice3 = alice;
	std::cout << alice3 << std::endl;

	return 0;
}
