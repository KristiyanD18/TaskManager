#pragma once
#include "User.h"
#include "Task.h"
#include "MyVector.hpp"
#include "Date.h"

class Dashboard
{
private:
	unsigned _idxOfUser;
	MyVector<Task> _tasks;

	int getTaskIdxByName(const MyString& name) const;
	int getTaskIdxById(unsigned id) const;

public:
	Dashboard() = default;
	Dashboard(unsigned idxOfUser);

	bool checkIfTaskExist(unsigned idxInSystem, const MyString& name, const MyString& desc, const Date& dueDate) const;
	void sortTasksById();

	void addTask(unsigned idxOfAuthor, const MyString& title, const MyString& content, const Date& dueDate);
	void printTasks() const;
	void printTasksInDashboard() const;
	void printCompletedTasks() const;

	unsigned getIdxOfUser() const;
	
	void getCurrentTaskByName(const MyString& title, Task*& currentTask);
	void getCurrentTaskById(unsigned id, Task*& currentTask);
	unsigned getCountOfTasks();  // not used

	void deleteTaskById(unsigned id);
	
	void writeToFile(std::ofstream& ofs) const;
	void readFromFiLe(std::ifstream& ifs);
};