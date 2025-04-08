/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:40:59 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 16:00:03 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

// test of bureaucrat

int main(void){

  Bureaucrat *bureaucrat = NULL;

  try {
    bureaucrat = new Bureaucrat("bureaucrat", 150);

    // print name
    std::cout << bureaucrat->getName() << std::endl;
    // print initial grade (150)
    std::cout << bureaucrat->getGrade() << std::endl;
    // print increment grade (149)
    bureaucrat->incrementGrade();
    std::cout << bureaucrat->getGrade() << std::endl;
    // print decrement grade (150)
    bureaucrat->decrementGrade();
    std::cout << bureaucrat->getGrade() << std::endl;
    // print decrement grade (151) *Error
    bureaucrat->decrementGrade();  // This will throw an exception (grade too low)
    std::cout << bureaucrat->getGrade() << std::endl;
    // print increment grade (-1) *Error
    for (int i = 0; i < 151; i++)
      bureaucrat->incrementGrade();  // This will throw an exception (grade too high)
    std::cout << bureaucrat->getGrade() << std::endl;

    delete bureaucrat;
    bureaucrat = NULL;

  } catch (std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  if (bureaucrat)
    delete bureaucrat;

  return 0;
}
