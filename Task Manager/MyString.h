#pragma once
#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* data); // constructor with parameters
	MyString(const MyString& other); // copy constructor
	MyString& operator=(const MyString& other);
	~MyString();

	MyString(MyString&& other) noexcept; // move constructor
	MyString& operator=(MyString&& other) noexcept; // move constructor with operator =

	size_t length() const;
	MyString& operator+=(const MyString& other); // operator +=

	MyString substr(size_t begin, size_t howMany) const;

	char& operator[](size_t index);
	char operator[](size_t index) const;

	const char* c_str() const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream&, MyString& str);

private:
	char* _data;
	size_t _length;

	void copyFrom(const MyString& data);
	void free();

	explicit MyString(size_t capacity); // the amount of memory (usually in bytes) to allocate for the internal buffer of the MyString object.
};

std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);