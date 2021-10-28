/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:14:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/17 02:02:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Karen {
	public:
	
	typedef void	(Karen::*ComplainFun)(void);
	
	Karen();
	~Karen();
	void	complain(std::string level);

	private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	static std::string	_debugMsg;
	static std::string	_infoMsg;
	static std::string	_warningMsg;
	static std::string	_errorMsg;
	static const char	*_levelStr[4];
	static ComplainFun	_levelFun[4];
};
