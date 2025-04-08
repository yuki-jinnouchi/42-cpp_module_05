/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:58:06 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 16:07:21 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/*make test*/

int main(void) {

  AForm* rrf = NULL;
  AForm* ppf = NULL;
  AForm* scf = NULL;

  try {

    Intern someRandomIntern;

    std::cout << "\n== Test of ShrubberyCreationForm ==" << std::endl;
    std::cout << "=== Construct ===" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat bender("Bender", 1);
    std::cout << "=== Execute ===" << std::endl;
    bender.signForm(*rrf);
    bender.executeForm(*rrf);
    std::cout << "=== Destruct ===" << std::endl;
    delete rrf;
    rrf = NULL;

    std::cout << "\n== Test of RobotomyRequestForm ==" << std::endl;
    std::cout << "=== Construct ===" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    Bureaucrat bender2("Bender", 1);
    std::cout << "=== Execute ===" << std::endl;
    bender2.signForm(*ppf);
    bender2.executeForm(*ppf);
    std::cout << "=== Destruct ===" << std::endl;
    delete ppf;
    ppf = NULL;

    std ::cout << "\n== Test of PresidentialPardonForm ==" << std::endl;
    std::cout << "=== Construct ===" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    Bureaucrat bender3("Bender", 1);
    std::cout << "=== Execute ===" << std::endl;
    bender3.signForm(*scf);
    bender3.executeForm(*scf);
    std::cout << "=== Destruct ===" << std::endl;
    delete scf;
    scf = NULL;

    std::cout << std::endl;
  }

  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (rrf)
    delete rrf;
  if (ppf)
    delete ppf;
  if (scf)
    delete scf;

  return 0;
}
