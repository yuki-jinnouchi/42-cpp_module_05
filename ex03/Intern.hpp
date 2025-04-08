/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:47:17 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:54:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
  Since filling out forms all day would be too cruel for our bureaucrats, interns exist to
  take on this tedious task. In this exercise, you must implement the Intern class. The
  intern has no name, no grade, and no unique characteristics. The only thing bureaucrats
  care about is that they do their job.

  However, the intern has one key ability: the makeForm() function. This function
  takes two strings as parameters: the first one represents the name of a form, and the
  second one represents the target of the form. It returns a pointer to a AForm object
  (corresponding to the form name passed as a parameter), with its target initialized to
  the second parameter.

  It should print something like:

  Intern creates <form>

  If the provided form name does not exist, print an explicit error message.
*/

class Intern {
  public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    // Member Functions
    AForm *makeForm(std::string formName, std::string target);

  // Exceptions
  class FormNotFoundException : public std::exception {
    public:
      virtual const char *what() const throw();
  };

};

#endif
