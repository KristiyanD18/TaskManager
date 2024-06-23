#pragma once
#include "MyString.h"
#include <ctime>
#include "SerializeFunctions.h"
#include "Date.h"

enum class Status
{
	ON_HOLD,
	IN_PROCESS,
	DONE,
	OVERDUE
};

class Task
{
private:
	unsigned _idxOfAuthor = 0;
	unsigned _id = 0;
	MyString _name = "Empty";
	MyString _description = "Empty";
	Date _dueDate;
	Status _status = Status::ON_HOLD;
	bool _isInDashboard = 0;

public:
	Task() = default;
	Task(unsigned idxOfAuthor, unsigned id, const MyString& name, const Date& dueDate, const Status& status, const MyString& description);
	Task(unsigned idxOfAuthor, unsigned id, const MyString& name, Status status, const MyString& description, time_t dueDate);

	MyString statusToString(Status status) const;

	bool isInDashboard() const;

	void setName(const MyString& name);
	void setDescription(const MyString& description);
	void setStatus(const Status& status);
	void setIsInDashboard(bool isInDashboard);

	unsigned getId() const;
	const MyString& getName() const;
	const MyString& getDescription() const;
	const Status& getStatus() const;
	const Date& getDueDate() const;

	void printTaskInfo() const;

	void writeToFile(std::ofstream& ofs) const;
	void readFromFiLe(std::ifstream& ifs);
};