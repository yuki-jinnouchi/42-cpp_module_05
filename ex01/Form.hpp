/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:28:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:15:30 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;

/*
  Let’s create a Form class. It has:
    • A constant name.
    • A boolean indicating whether it is signed (at construction, it is not).
    • A constant grade required to sign it.
    • A constant grade required to execute it.
  All these attributes are private, not protected.

  The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
  following exceptions will be thrown if a form’s grade is out of bounds:
  Form::GradeTooHighException and Form::GradeTooLowException.

  As before, write getters for all attributes and overload the insertion («) operator to
  print all the form’s information.
*/

class Form {
  private:
    // Private attributes
    std::string const _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

  public:
    // Orthodox Canonical Form
    Form();
    ~Form();
    Form(const Form &src);
    Form &operator=(const Form &rhs);

    // Optional constructor
    Form(const std::string &name, int gradeToSign, int gradeToExecute);

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

// ostream overload
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
