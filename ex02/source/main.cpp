/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:28:21 by strieste          #+#    #+#             */
/*   Updated: 2026/03/17 13:53:12 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"

int	main(void)
{
	std::string	name = "Boss";
	std::string	nameForm1 = "Form1";
	std::string	nameForm2 = "Form2";
	std::string	nameForm3 = "Form3";

	Form	facture;
	Form	facture1(nameForm1, 51, 51);
	Form	facture2(nameForm2, 1, 1);
	Form	facture3(nameForm3, 51, 51, true);

	Bureaucrat	boss(name, 51);

	std::cout << facture;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.signForm(facture);
	std::cout << std::endl;
	std::cout << facture1;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.signForm(facture1);
	std::cout << std::endl;
	std::cout << facture2;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.signForm(facture2);
	std::cout << std::endl;
	std::cout << facture3;
	std::cout << "Grade Boss: " << boss.getGrade() << std::endl;
	boss.signForm(facture3);

	return (0);
}