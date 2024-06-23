#pragma once
#include "User.h"
#include "Dashboard.h"
#include "MyVector.hpp"
#include "Date.h"

class TaskManager
{
private:
	MyVector<User> _users;
	MyVector<Dashboard> _dashboards;
	User* _currentU = nullptr;
	Dashboard* _currentD = nullptr;
	Task* _currentT = nullptr;

	int getUserIdx(const MyString& username, const MyString& password) const;
	int getDashboardIdxByUser(const User*& user) const;

public:
	// authentication methods
	void registerUser(const MyString& username, const MyString& password);
	void login(const MyString& username, const MyString& password);
	void logout();
	bool isLoggedIn() const;
	void exit();

	// task methods
	void addTask(const MyString& name, const MyString& desc, const Date& dueDate);
	void updateTaskName(unsigned id, const MyString& newName);
	void updateTaskDescription(unsigned id, const MyString& newDescription);
	void deleteTask(unsigned id);
	void getTask(const MyString& name);
	void getTask(unsigned id);
	void startTask(unsigned id);
	void finishTask(unsigned id);
		// print methods
	void listCompletedTasks() const;
	void listTasks() const;

	// dashboard methods
	void addTaskToDashboard(unsigned id);
	void removeTaskFromDashboard(unsigned id);
	void listDashboard() const; // print method

	// collaboration methods
	void addCol(const MyString& name);
	void deleteCol(const MyString& name);
	void listCols() const;
	void addUser(const MyString& colName, const MyString& userName);
	void assignTask(const MyString& colName, const MyString& userName, const Date& dueDate);
	void listColTasks() const; // print method

	// serialization methods
	void writeToFile() const;
	void readFromFiLe();

	~TaskManager();
};