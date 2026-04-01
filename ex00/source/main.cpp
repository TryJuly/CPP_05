/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:21 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 06:15:29 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "../header/Bureaucrat.hpp"
#include <string>
#include <iostream>

int main() {

    std::cout << "--- Test constructeur valide ---" << std::endl;
    Bureaucrat alice("Alice", 50);
    std::cout << alice << std::endl;

    std::cout << "\n--- Test constructeur grade trop haut ---" << std::endl;
    try {
        Bureaucrat bad("Bad", 0);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test constructeur grade trop bas ---" << std::endl;
    try {
        Bureaucrat bad("Bad", 151);
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test incrementGrade ---" << std::endl;
    Bureaucrat bob("Bob", 2);
    std::cout << bob << std::endl;
    bob.incrementGrade();
    std::cout << bob << std::endl;

    std::cout << "\n--- Test incrementGrade depasse ---" << std::endl;
    try {
        bob.incrementGrade(); // grade = 1, va throw
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test decrementGrade ---" << std::endl;
    Bureaucrat charlie("Charlie", 149);
    std::cout << charlie << std::endl;
    charlie.decrementGrade();
    std::cout << charlie << std::endl;

    std::cout << "\n--- Test decrementGrade depasse ---" << std::endl;
    try {
        charlie.decrementGrade(); // grade = 150, va throw
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test copy constructor ---" << std::endl;
    Bureaucrat alice2(alice);
    std::cout << alice2 << std::endl;

    std::cout << "\n--- Test operator= ---" << std::endl;
    Bureaucrat alice3("Temp", 100);
    alice3 = alice;
    std::cout << alice3 << std::endl;

    return 0;
}

// int	main(void)
// {
// 	std::string	name = "Boss";
	
// 	std::cout << "###	Try to init boss with grade 0	###" << std::endl;
// 	std::cout << std::endl;
// 	try
// 	{
// 		Bureaucrat	Boss(name, 0);
// 		std::cout << Boss;
// 	}
// 	catch (Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cerr << e.what();
// 	}

// 	std::cout << std::endl;

// 	std::cout << "###	Try to increment/decrement	###" << std::endl;
// 	std::cout << std::endl;
// 	try
// 	{
// 		Bureaucrat	Boss1(name, 1);
// 		std::cout << Boss1;
// 		std::cout << "Try to increment Boss grade" << std::endl;
// 		Boss1.increment();
// 	}
// 	catch (Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cerr << e.what();
// 	}
// 	std::cout << std::endl;
// 	try
// 	{
// 		Bureaucrat	JuniorIT;
// 		std::cout << JuniorIT;
// 		std::cout << "Try to decrement Junior grade" << std::endl;
// 		JuniorIT.decrement();
// 	}
// 	catch(Bureaucrat::GradeTooLowException& e)
// 	{
// 		std::cout << e.what();
// 	}
	
// 	std::cout << std::endl;

// 	std::cout << "###	Try loop decrementation	###" << std::endl;
// 	std::cout << std::endl;
// 	try
// 	{
// 		std::string	name = "JuniorIT";
// 		Bureaucrat	JuniorIT(name, 9);
		
// 		for (int i = 0; i < 10; i++)
// 		{
// 			std::cout << JuniorIT;
// 			JuniorIT.increment();
// 		}
// 	}
// 	catch(Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cout << e.what();
// 		return (1);
// 	}

// 	return (0);
// }