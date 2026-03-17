/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:21 by strieste          #+#    #+#             */
/*   Updated: 2026/03/17 09:48:31 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::string	name = "Boss";
	
	std::cout << "###	Try to init boss with grade 0	###" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat	Boss(name, 0);
		std::cout << Boss;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what();
	}

	std::cout << std::endl;

	std::cout << "###	Try to increment/decrement	###" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat	Boss1(name, 1);
		std::cout << Boss1;
		std::cout << "Try to increment Boss grade" << std::endl;
		Boss1.increment();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	JuniorIT;
		std::cout << JuniorIT;
		std::cout << "Try to decrement Junior grade" << std::endl;
		JuniorIT.decrement();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what();
	}
	
	std::cout << std::endl;

	std::cout << "###	Try loop decrementation	###" << std::endl;
	std::cout << std::endl;
	try
	{
		std::string	name = "JuniorIT";
		Bureaucrat	JuniorIT(name, 9);
		
		for (int i = 0; i < 10; i++)
		{
			std::cout << JuniorIT;
			JuniorIT.increment();
		}
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what();
		return (1);
	}
	return (0);
}