/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:41:45 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/03/14 17:19:04 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat()
  : _name("default"), _grade(150){};

Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(Bureaucrat const &srcs)
  : _name(srcs._name), _grade(srcs._grade){
};

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs){
  if (this == &rhs)
    return *this;
  this->_grade = rhs._grade;
  // _name is const, so we can't change it
  return *this;
};

// Optional Constructor
Bureaucrat::Bureaucrat(std::string name, int grade)
  : _name(name), _grade(grade){
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

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw(){
  return "Grade is too high";
};

const char *Bureaucrat::GradeTooLowException::what() const throw(){
  return "Grade is too low";
};

// ostream overload
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs){
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return o;
};
