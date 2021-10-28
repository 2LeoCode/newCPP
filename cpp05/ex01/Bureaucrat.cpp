/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:54 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/26 20:57:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define M(memberName) Bureaucrat::memberName

M(Bureaucrat)() : _name("Unnamed Bureaucrat"), _grade(150) { }

M(~Bureaucrat)() { }

M(Bureaucrat)(const Bureaucrat &other) : _name(other._name),
_grade(other._grade) { }

M(Bureaucrat)(std::string name) : _name(name), _grade(150) { }

M(Bureaucrat)(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) throw (M(GradeTooHighException()));
	if (grade > 150) throw (M(GradeTooLowException()));
}

const std::string	&M(getName)(void) const {
	return (_name);
}

int	M(getGrade)(void) const {
	return (_grade);
}

void	M(upgrade)(void) {
	if (--_grade < 1) throw (M(GradeTooHighException()));
}

void	M(downgrade)(void) {
	if (++_grade > 150) throw (M(GradeTooLowException()));
}

const char	*M(GradeTooHighException::what)(void) const throw () {
	return "Grade too high";
}

const char	*M(GradeTooLowException::what)(void) const throw () {
	return "Grade too low";
}
