#include "SerializeFunctions.h"

void writeStringToFile(std::ofstream& ofs, const MyString& str)
{
	int length = str.length();
	ofs.write((const char*)&length, sizeof(int));

	ofs.write(str.c_str(), sizeof(char) * length);
}

MyString readStringFromFile(std::ifstream& ifs)
{
	int length = 0;
	ifs.read((char*)&length, sizeof(length));

	char* buff = new char[length + 1];
	ifs.read(buff, sizeof(char) * length);

	buff[length] = '\0';

	MyString toReturn(buff);

	delete[] buff;

	return toReturn;
}