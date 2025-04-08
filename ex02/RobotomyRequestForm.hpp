/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:38 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 13:00:26 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

/*
  RobotomyRequestForm: Required grades: sign 72, exec 45
  Makes some drilling noises, then informs that <target> has been robotomized
  successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

class RobotomyRequestForm : public AForm {
  public:
    // Orthodox Canonical Form
    ~RobotomyRequestForm();

    // Optional constructor
    RobotomyRequestForm(const std::string &target);

    // Member Functions
    void execute(Bureaucrat const &executor) const;
};

#endif
