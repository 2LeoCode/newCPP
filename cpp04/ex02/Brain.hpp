/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:14:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/24 17:28:18 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	public:

	Brain();
	~Brain();

	Brain(const Brain &other);

	Brain	&operator=(const Brain &other);

	private:

	std::string	_ideas[100];
};

#endif //BRAIN_HPP
