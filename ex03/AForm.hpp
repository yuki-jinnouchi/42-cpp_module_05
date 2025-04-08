/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:28:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/09 01:10:03 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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

class AForm {
  private:
    // Private attributes
    std::string const _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExecute;
    std::string _target;

  public:
    // Orthodox Canonical Form
    AForm();
    virtual ~AForm();
    AForm(const AForm &src);
    AForm &operator=(const AForm &rhs);

    // Optional constructor
    AForm(const std::string &name, int gradeToSign, int gradeToExecute, std::string target);

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    std::string getTarget() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);
    bool isExecutable(const Bureaucrat &executor) const;
    virtual void execute(const Bureaucrat &executor) const = 0;

    // Exceptions
    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class FormNotExecutableException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

// ostream overload
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
