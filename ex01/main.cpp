/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:40:59 by yjinnouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:33:24 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// test of From class

int main(void){
  try {
    // Preare Bureaucrats with different grades
    Bureaucrat b1("B1", 1);    // Highest grade
    Bureaucrat b2("B2", 150);  // Lowest grade
    std::cout << std::endl;

    // Prepare Forms with different grade requirements
    Form f1("F1", 1, 1);
    Form f2("F2", 150, 150);
    Form f3("F3", 1, 150);
    Form f4("F4", 150, 1);

    // Print initial state
    std::cout << "\n=== Initial state ===" << std::endl;
    std::cout << b1;
    std::cout << b2;
    std::cout << f1;
    std::cout << f2;
    std::cout << f3;
    std::cout << f4;

    // Test successful signing
    std::cout << "\n=== Test successful signing ===" << std::endl;
    b1.signForm(f1);  // b1 (grade 1) signs f1 (requires grade 1) - should succeed
    b2.signForm(f2);  // b2 (grade 150) signs f2 (requires grade 150) - should succeed
    b1.signForm(f3);  // b1 (grade 1) signs f3 (requires grade 1) - should succeed

    // Test unsuccessful signing
    std::cout << "\n=== Test unsuccessful signing ===" << std::endl;
    b2.signForm(f1);  // b2 (grade 150) signs f1 (requires grade 1) - should fail
    b2.signForm(f3);  // b2 (grade 150) signs f3 (requires grade 1) - should fail

    // Print final state
    std::cout << "\n=== Final state ===" << std::endl;
    std::cout << f1;
    std::cout << f2;
    std::cout << f3;
    std::cout << f4;

    std::cout << std::endl;

  } catch (std::exception & e){
    std::cout << e.what() << std::endl;

  }
}
