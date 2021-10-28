/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 04:50:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/16 14:26:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

#include <ctime>
#include <cstdlib>

#define M(memberName) Account::memberName

static std::string		timeStamp;
static std::ofstream	out;
static bool				init = false;

int	M(_nbAccounts)(0);
int	M(_totalAmount)(0);
int	M(_totalNbDeposits)(0);
int	M(_totalNbWithdrawals)(0);

static void	closeLogFile(void) {
	out.close();
}

int	M(getNbAccounts)(void) {
	return (_nbAccounts);
}
int	M(getTotalAmount)(void) {
	return (_totalAmount);
}

int	M(getNbDeposits)(void) {
	return (_totalNbDeposits);
}

int	M(getNbWithdrawals)(void) {
	return (_totalNbWithdrawals);
}

void	M(displayAccountsInfos)(void) {
	_displayTimestamp();
	out << "accounts:" << _nbAccounts << ';';
	out << "total:" << _totalAmount << ';';
	out << "deposits:" << _totalNbDeposits << ';';
	out << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

M(Account)(int initial_deposit) : _accountIndex(_nbAccounts++),
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	std::ostringstream	timeStampStream;
	time_t				rawTime(time(nullptr));
	struct tm			*timeinfo;
	static bool			init(false);

	timeinfo = localtime(&rawTime);
	_totalAmount += _amount;
	timeStampStream << timeinfo->tm_year + 1900;
	timeStampStream << timeinfo->tm_mon + 1 << timeinfo->tm_mday;
	timeStampStream << '_';
	timeStampStream << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec;
	timeStamp = timeStampStream.str();
	if (!init) {
		init = true;
		out.open(timeStamp + ".log", std::ios::out);
		std::atexit(closeLogFile);
	}
	_displayTimestamp();
	out << "index:" << _accountIndex << ';';
	out << "amount:" << _amount << ";created" << std::endl;
}

M(~Account)(void) {
	_displayTimestamp();
	out << "index:" << _accountIndex << ';';
	out << "amount:" << _amount << ";closed" << std::endl;
}

void	M(makeDeposit)(int deposit) {
	++_totalNbDeposits;
	_totalAmount += deposit;
	_displayTimestamp();
	out << "index:" << _accountIndex << ';';
	out << "p_amount:" << _amount << ';';
	_amount += deposit;
	out << "deposit:" << deposit << ';';
	out << "amount:" << _amount << ';';
	out << "nb_deposits:" << ++_nbDeposits << std::endl;
}

bool	M(makeWithdrawal)(int withdrawal) {
	_displayTimestamp();
	out << "index:" << _accountIndex << ';';
	out << "p_amount:" << _amount << ';';
	out << "withdrawal:";
	_amount -= withdrawal;
	if (!checkAmount()) {
		out << "refused" << std::endl;
		_amount += withdrawal;
		return (false);
	}
	++_totalNbWithdrawals;
	_totalAmount -= withdrawal;
	out << withdrawal << ';';
	out << "amount:" << _amount << ';';
	out << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	return (true);
}

int		M(checkAmount)(void) const {
	return (_amount >= 0);
}

void	M(displayStatus)(void) const {
	_displayTimestamp();
	out << "index:" << _accountIndex << ';';
	out << "amount:" << _amount << ';';
	out << "deposits:" << _nbDeposits << ';';
	out << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	M(_displayTimestamp)(void) {
	out << '[' << timeStamp << "] ";
}
