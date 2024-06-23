#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "Task.h"
#include "User.h"

class Collaboration
{
private:
	unsigned id;
	MyString name;
	MyString creatorName; // or idxOfCreator
	MyVector<User> users; // or UserForCollabs class inherits User
	MyVector<Task> tasks;

public:
	Collaboration() = default;
	Collaboration(unsigned id, const MyString& name, const MyString& creatorName, const MyString& creator);
	void addUser(const MyString& username);


	void addTask(const Task& task);
};