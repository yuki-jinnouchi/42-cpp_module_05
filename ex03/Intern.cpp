/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:47:14 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 15:52:09 by yjinnouc         ###   ########.fr       */
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

  if (formName == "shrubbery creation") {
    form = new ShrubberyCreationForm(target);
  } else if (formName == "robotomy request") {
    form = new RobotomyRequestForm(target);
  } else if (formName == "presidential pardon") {
    form = new PresidentialPardonForm(target);
  } else {
    throw FormNotFoundException();
  }

  std::cout << "Intern creates " << form->getName() << std::endl;
  return form;
}

// Exceptions
const char* Intern::FormNotFoundException::what() const throw() {
  return "Intern: Form not found";
}
