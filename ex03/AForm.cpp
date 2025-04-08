/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:28:05 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:19:12 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Orthodox Canonical Form
AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
  std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm() {
  std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& other)
  : _name(other._name), _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
  std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
  std::cout << "AForm assignment operator called" << std::endl;
  if (this != &other) {
    _isSigned = other._isSigned;
  }
  return *this;
}

// Optional constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, std::string target)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target){
  std::cout << "AForm parametrized constructor called" << std::endl;

  if (gradeToSign < 1 || gradeToExecute < 1)
    throw AForm::GradeTooHighException();

  if (gradeToSign > 150 || gradeToExecute > 150)
    throw AForm::GradeTooLowException();
}

// Getters
std::string AForm::getName() const {
  return _name;
}

bool AForm::getIsSigned() const {
  return _isSigned;
}

int AForm::getGradeToSign() const {
  return _gradeToSign;
}

int AForm::getGradeToExecute() const {
  return _gradeToExecute;
}

std::string AForm::getTarget() const {
  return _target;
}

// Member functions
void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= _gradeToSign) {
    _isSigned = true;
  } else {
    throw AForm::GradeTooLowException();
  }
}

bool AForm::isExecutable(const Bureaucrat& executor) const {
  if (!getIsSigned()){
    throw AForm::FormNotExecutableException();
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() >= _gradeToExecute) {
    throw AForm::FormNotExecutableException();
    throw AForm::GradeTooLowException();
  }
  return true;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

const char* AForm::FormNotExecutableException::what() const throw() {
  return "Form is not executable";
}

// ostream overload
std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << "Form '" << form.getName() << "', ";
  os << "signed status: " << (form.getIsSigned() ? "signed" : "not signed") << ", ";
  os << "grade required to sign: " << form.getGradeToSign() << ", ";
  os << "grade required to execute: " << form.getGradeToExecute();
  os << std::endl;
  return os;
}
