/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:43 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 15:47:09 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

/*
  ShrubberyCreationForm: Required grades: sign 145, exec 137
  Creates a file <target>_shrubbery in the working directory and writes ASCII trees
  inside it.
*/

class ShrubberyCreationForm : public AForm {
  public:
    // Orthodox Canonical Form
    ~ShrubberyCreationForm();

    // Optional constructor
    ShrubberyCreationForm(const std::string &target);

    // Member Functions
    void execute(Bureaucrat const &executor) const;
};

#endif
