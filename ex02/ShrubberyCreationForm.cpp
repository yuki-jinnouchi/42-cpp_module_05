/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:41 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 13:00:05 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Orthodox Canonical Form
ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Optional constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
  : AForm("Shrubbery Creation Form", 145, 137, target) {
  std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

// Member Functions
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->isExecutable(executor))
    throw AForm::GradeTooLowException();

  std::ofstream ofs(getTarget() + "_shrubbery");
  if (!ofs.is_open()) {
    std::cerr << "Error: Could not open file." << std::endl;
    return;
  }

  ofs << "     &&& &&  & &&\n"
    << "   && &\\/&\\|& ()|/ @, &&\n"
    << "   &\\/(/&/&||/& /_/)_&/_&\n"
    << "&() &\\/&|()|/&\\/ '%\" & ()\n"
    << "&_\\/&_/&&&|&&|\\/&\\_/_&/_&\n"
    << "&&   && & &| &| /& & % ()& /&&\n"
    << " ()&_---()&\\&\\|&&-&&--%---()~\n"
    << "     &&     \\|||\n"
    << "             |||\n"
    << "             |||\n"
    << "             |||\n"
    << "         , -=-~.-^- _\n"
    << std::endl;

  ofs.close();
}

