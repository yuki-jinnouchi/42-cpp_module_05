/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:41:58 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:08:57 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

#include "AForm.hpp"

class AForm;

/*
  A Bureaucrat must have:
    •A constant name.
    •And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
      grade).
  Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception: either
    a Bureaucrat::GradeTooHighException or
    a Bureaucrat::GradeTooLowException.

  You will provide getters for both these attributes
  : getName() and getGrade().
  Implement also two member functions to increment or decrement the bureaucrat grade.
  If the grade is out of range, both of them will throw the same exceptions as the constructor
*/

class Bureaucrat {
  private:
    std::string const _name;
    int _grade;

  public:
    // Orthodox Canonical Form
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const &srcs);
    Bureaucrat &operator=(Bureaucrat const &rhs);

    // Optional Constructor
    Bureaucrat(std::string name, int grade);

    // Getters and Setters
    std::string getName(void) const;
    int getGrade(void) const;

    // Member Functions
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(AForm &form);
    void executeForm(AForm const &form);

    // Exceptions
    class GradeTooHighException
    : public std::exception{
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException
    : public std::exception{
      public:
        virtual const char *what() const throw();
    };
};

// ostream overload
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
