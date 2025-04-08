/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:47:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/09 01:08:35 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Orthodox Canonical Form
Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
  std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
  std::cout << "Intern copy constructor called" << std::endl;
  *this = other;
}

Intern& Intern::operator=(const Intern& other) {
  std::cout << "Intern assignment operator called" << std::endl;
  if (this != &other) {}
  return *this;
}

// Member Functions
AForm* Intern::makeForm(std::string formName, std::string target) {
  AForm* form = NULL;

  std::string formNames[3] = {
    "presidential pardon",
    "robotomy request",
    "shrubbery creation"
  };

  int i = 0;
  while (i < 3 && formName != formNames[i]) {
    i++;
  }

  switch (i) {
    case 0:
      form = new PresidentialPardonForm(target);
      break;
    case 1:
      form = new RobotomyRequestForm(target);
      break;
    case 2:
      form = new ShrubberyCreationForm(target);
      break;
    default:
      throw FormNotFoundException();
  }

  std::cout << "Intern creates " << form->getName() << std::endl;
  return form;
}

// Exceptions
const char* Intern::FormNotFoundException::what() const throw() {
  return "Intern: Form not found";
}
