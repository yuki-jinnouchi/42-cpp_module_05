/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:41:45 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:18:23 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat()
    : _name("default"), _grade(150){
    std::cout << "Bureaucrat Default constructor called" << std::endl;
};

Bureaucrat::~Bureaucrat(){
  std::cout << "Bureaucrat Destructor called" << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat const &srcs)
  : _name(srcs._name), _grade(srcs._grade){
  std::cout << "Bureaucrat Copy constructor called" << std::endl;
  };

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs){
  std::cout << "Bureaucrat Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  this->_grade = rhs._grade;
  return *this;
};

// Optional Constructor
Bureaucrat::Bureaucrat(std::string name, int grade)
  : _name(name), _grade(grade){
  std::cout << "Bureaucrat Parameterized constructor called" << std::endl;
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
};

// Getters and Setters
std::string Bureaucrat::getName(void) const{
  return this->_name;
};

int Bureaucrat::getGrade(void) const{
  return this->_grade;
};

// Member Functions
void Bureaucrat::incrementGrade(void){
  if (this->_grade - 1 < 1)
    throw GradeTooHighException();
  this->_grade--;
};

void Bureaucrat::decrementGrade(void){
  if (this->_grade + 1 > 150)
    throw GradeTooLowException();
  this->_grade++;
};

/*
  Then, modify the signForm() member function in the Bureaucrat class. This function must call Form::beSigned() to attempt to sign the form. If the form is signed successfully, it will print something like:

  <bureaucrat> signed <form>

  Otherwise, it will print something like:

  <bureaucrat> couldn’t sign <form> because <reason>.
*/

void Bureaucrat::signForm(Form &form){
  try {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
  }
};

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw(){
  return "Grade is too high";
};

const char *Bureaucrat::GradeTooLowException::what() const throw(){
  return "Grade is too low";
};

// ostream overload
std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs){
  os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return os;
};
