#include "Account.h"

Account::Account(string _name, int _id, int _balance)
{
	name = _name;
	id = _id;
	balance = _balance;
}

void Account::deposit(int _money)
{
	balance += _money;
}

int Account::withdraw(int _money)
{
	balance -= _money;
	return balance;
}

string Account::getOwner()
{
	return name;
}

int Account::inquiry()
{
	return balance;
}
