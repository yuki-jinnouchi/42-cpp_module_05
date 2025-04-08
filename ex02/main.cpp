/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:58:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:55:48 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*make test*/

int main(void) {
  try {
    Bureaucrat b1("B1", 1); // Highest grade
    Bureaucrat b2("B2", 150); // Lowest grade
    std::cout << std::endl;
    PresidentialPardonForm ppf("Target1");
    RobotomyRequestForm rrf("Target2");
    ShrubberyCreationForm scf("Target3");

    std::cout << "\n=== Initial state ===" << std::endl;
    std::cout << b1;
    std::cout << b2;
    std::cout << ppf;
    std::cout << rrf;
    std::cout << scf;

    // Test signing and executing forms
    std::cout << "\n= Test of Bureaucrat signing and executing forms ==" << std::endl;

    std::cout << "\n== Test of ShrubberyCreationForm ==" << std::endl;
    std::cout << "=== Success Cases ===" << std::endl;
    b1.signForm(scf);
    b1.executeForm(scf);
    std::cout << "=== Unsuccess Cases ===" << std::endl;
    b2.signForm(scf);
    b2.executeForm(scf);

    std::cout << "\n== Test of RobotomyRequestForm ==" << std::endl;
    std::cout << "=== Success Cases ===" << std::endl;
    b1.signForm(rrf);
    b1.executeForm(rrf);
    std::cout << "=== Unsuccess Cases ===" << std::endl;
    b2.signForm(rrf);
    b2.executeForm(rrf);

    std ::cout << "== Test of PresidentialPardonForm ==" << std::endl;
    std::cout << "=== Success Cases ===" << std::endl;
    b1.signForm(ppf);
    b1.executeForm(ppf);
    std::cout << "=== Unsuccess Cases ===" << std::endl;
    b2.signForm(ppf);
    b2.executeForm(ppf);

    std::cout << std::endl;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;

  }
  return 0;
}
