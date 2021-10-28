/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:50:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/17 15:23:49 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void) {
	Karen	karen;

	karen.complain("WARNING");
	karen.complain("DEBUG");
	karen.complain("ERROR");
	karen.complain("INFO");
	karen.complain("LOL");
	return (0);
}
