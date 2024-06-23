#pragma once
#include "User.h"
#include "Task.h"
#include "MyVector.hpp"
#include "Date.h"

class Dashboard
{
private:
	unsigned _idxOfUser = 0;
	MyVector<Task> _tasks;

	int getTaskIdxByName(const MyString& name) const;
	int getTaskIdxById(unsigned id) const;

public:
	Dashboard() = default;
	Dashboard(unsigned idxOfUser);

	void addTasksDueTodayToDashboardAndRemoveOverdued(); // after login
	bool checkIfTaskExists(unsigned idxInSystem, const MyString& name, const MyString& desc, const Date& dueDate) const;
	void sortTasksById();

	void addTask(unsigned idxOfAuthor, const MyString& title, const MyString& content, const Date& dueDate);
	void deleteTaskById(unsigned id);

	unsigned getIdxOfUser() const;

	void getCurrentTaskByName(const MyString& title, Task*& currentTask);
	void getCurrentTaskById(unsigned id, Task*& currentTask);
	unsigned getCountOfTasks();
	

	// print methods
	void printTasks() const;
	void printTasksInDashboard() const;
	void printCompletedTasks() const;
	void printTasksWithDeadLineTo(const Date& date) const;

	// serialization methods
	void writeToFile(std::ofstream& ofs) const;
	void readFromFiLe(std::ifstream& ifs);
};