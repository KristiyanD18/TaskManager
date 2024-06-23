#pragma once
#include "MyString.h"
#include "SerializeFunctions.h"

class User
{
private:
	MyString _username = "Unknown";
	MyString _password = "N / A";
	unsigned _id = 0;
	unsigned _idxInSystem = 0;

public:
	User() = default;
	User(const MyString& username, const MyString& password, unsigned id, unsigned idxInSystem);

	bool isPassword(const MyString& password) const;
	bool isUsername(const MyString& username) const;

	const MyString& getUsername() const;
	unsigned getId() const;
	unsigned getIdxInSystem() const;


	void writeToFile(std::ofstream& ofs) const;
	void readFromFiLe(std::ifstream& ifs);
};