/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:34 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:59:30 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

/*
  PresidentialPardonForm: Required grades: sign 25, exec 5
  Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

class PresidentialPardonForm : public AForm {
  public:
    // Orthodox Canonical Form
    ~PresidentialPardonForm();

    // Optional constructor
    PresidentialPardonForm(const std::string &target);

    // Member Functions
    void execute(Bureaucrat const &executor) const;
};

#endif
