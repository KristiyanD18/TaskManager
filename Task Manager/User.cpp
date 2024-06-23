#include "User.h"


User::User(const MyString& username, const MyString& password, unsigned id, unsigned idxInSystem) : _username(username), _password(password)
{
	_id = id;
	_idxInSystem = idxInSystem;
}

bool User::isPassword(const MyString& password) const
{
	return password == _password;
}

bool User::isUsername(const MyString& username) const
{
	return username == _username;
}

const MyString& User::getUsername() const
{
	return _username;
}

unsigned User::getId() const
{
	return _id;
}

unsigned User::getIdxInSystem() const
{
	return _idxInSystem;
}

void User::writeToFile(std::ofstream& ofs) const
{
	writeStringToFile(ofs, _username);
	writeStringToFile(ofs, _password);
	ofs.write((const char*)&_id, sizeof(unsigned));
	ofs.write((const char*)&_idxInSystem, sizeof(unsigned));
}

void User::readFromFiLe(std::ifstream& ifs)
{
	_username = readStringFromFile(ifs);
	_password = readStringFromFile(ifs);
	ifs.read((char*)&_id, sizeof(unsigned));
	ifs.read((char*)&_idxInSystem, sizeof(unsigned));
}