#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int Account::getNbAccounts(void) { return (Account::_nbAccounts);}
int Account::getTotalAmount(void) { return (Account::_totalAmount);}
int Account::getNbDeposits(void) {return (Account::_totalNbDeposits);}
int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals);}

Account::Account (int initial_deposit){
	this->_accountIndex = Account::getNbAccounts();
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	_nbAccounts--;
}

void	Account::_displayTimestamp(void){
	time_t curTime = time(NULL);
	struct tm *locTime = localtime(&curTime);
	char buff[20];
	strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S]", locTime);
	std::cout << buff << " ";
	return ;
}

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit){
	const int	oldAmount = this->_amount;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << oldAmount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}


bool	Account::makeWithdrawal(int withdrawal){
	const int	oldAmount = this->_amount;
	bool refused = false;

	if (oldAmount - withdrawal < 0)
		refused = true;
	if (!refused){
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
	}

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << oldAmount;
	if (refused){
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const{
	return (this->_amount);
}
void	Account::displayStatus(void)  const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}
