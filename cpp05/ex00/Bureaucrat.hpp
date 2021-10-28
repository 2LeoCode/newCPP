/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/27 15:40:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat {
	public:

	Bureaucrat();
	~Bureaucrat();

	Bureaucrat(const Bureaucrat &other);

	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);

	const std::string	&getName(void) const;
	int					getGrade(void) const;

	void				upgrade(void);
	void				downgrade(void);

	class GradeTooHighException : public std::exception {
		virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char	*what() const throw();
	};


	private:

	const std::string	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat &b);

#endif //BUREAUCRAT_HPP
