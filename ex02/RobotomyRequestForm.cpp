/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:36 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:59:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Orthodox Canonical Form
RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Optional constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
  : AForm("Robotomy Request Form", 72, 45, target) {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

// Member Functions
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->isExecutable(executor))
    throw AForm::GradeTooLowException();
  std::cout << "Drilling noises..." << std::endl;
  if (rand() % 2 == 0)
    std::cout << getTarget() << " has been robotomized successfully." << std::endl;
  else
    std::cout << "Robotomy failed for " << getTarget() << "." << std::endl;
}
