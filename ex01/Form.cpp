/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:28:05 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:18:27 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Orthodox Canonical Form
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
  std::cout << "Form default constructor called" << std::endl;
}

Form::~Form() {
  std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& other)
  : _name(other._name), _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
  std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
  std::cout << "Form assignment operator called" << std::endl;
  if (this != &other) {
    _isSigned = other._isSigned;
  }
  return *this;
}

// Optional constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  std::cout << "Form parametrized constructor called" << std::endl;

  if (gradeToSign < 1 || gradeToExecute < 1)
  throw Form::GradeTooHighException();

  if (gradeToSign > 150 || gradeToExecute > 150)
  throw Form::GradeTooLowException();
}

// Getters
std::string Form::getName() const {
  return _name;
}

bool Form::getIsSigned() const {
  return _isSigned;
}

int Form::getGradeToSign() const {
  return _gradeToSign;
}

int Form::getGradeToExecute() const {
  return _gradeToExecute;
}

// Member functions
/*
  Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
  parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
  (greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
  If the grade is too low, throw a Form::GradeTooLowException.
*/
void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= _gradeToSign) {
    _isSigned = true;
  } else {
    throw Form::GradeTooLowException();
  }
}

// Exception classes implementation
const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

// ostream overload
std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "Form '" << form.getName() << "', ";
  os << "signed status: " << (form.getIsSigned() ? "signed" : "not signed") << ", ";
  os << "grade required to sign: " << form.getGradeToSign() << ", ";
  os << "grade required to execute: " << form.getGradeToExecute();
  os << std::endl;
  return os;
}
