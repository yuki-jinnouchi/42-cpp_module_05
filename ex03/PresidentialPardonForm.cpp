/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:30 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:59:44 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form
PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Optional constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
  : AForm("Presidential Pardon Form", 25, 5, target){
  std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

// Member Functions
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->isExecutable(executor))
    throw AForm::GradeTooLowException();
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
