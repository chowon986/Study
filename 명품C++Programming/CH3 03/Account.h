#pragma once
#include <string>
using namespace std;

class Account
{
public:
	string name;
	int id;
	int balance;

public:
	Account(string _name, int _id, int _balance);
	
public:
	void deposit(int _money);
	int withdraw(int _money);
	string getOwner();
	int inquiry();
};

