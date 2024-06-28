#include "Task.h"
#include <fstream>

Task::Task(unsigned idxOfAuthor, unsigned id, const MyString& name, const Date& dueDate, const Status& status, const MyString& description) : _description(description), _name(name)
{
	_dueDate = dueDate;
	_idxOfAuthor = idxOfAuthor;
	_id = id;
}

MyString Task::statusToString(Status status) const
{
	switch (status)
	{
	case Status::ON_HOLD:
		return "ON_HOLD";
		break;
	case Status::IN_PROCESS:
		return "IN_PROCESS";
		break;
	case Status::DONE:
		return "DONE";
		break;
	case Status::OVERDUE:
		return "OVERDUE";
		break;
	default: 
		return "UNKNOWN";
		break;
	}
}

void Task::printTaskInfo() const
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "ID: " << _id << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Description: " << _description << std::endl;
	std::cout << "Due date: "; 
	_dueDate.printDate();
	std::cout << "Status: " << statusToString(_status) << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void Task::setName(const MyString& name)
{
	_name = name;
}

void Task::setDescription(const MyString& description)
{
	_description = description;
}

void Task::setStatus(const Status& status)
{
	_status = status;
}

void Task::setIsInDashboard(bool isInDashboard)
{
	if (_status != Status::OVERDUE)
	{
		_isInDashboard = isInDashboard;
	}
}

unsigned Task::getId() const
{
	return _id;
}

const MyString& Task::getName() const
{
	return _name;
}

const MyString& Task::getDescription() const
{
	return _description;
}

const Status& Task::getStatus() const
{
	return _status;
}

const Date& Task::getDueDate() const
{
	return _dueDate;
}

bool Task::isInDashboard() const
{
	return _isInDashboard;
}

void Task::writeToFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&_idxOfAuthor, sizeof(unsigned));
	writeStringToFile(ofs, _name);
	writeStringToFile(ofs, _description);
	ofs.write((const char*)&_dueDate, sizeof(Date));
	ofs.write((const char*)&_status, sizeof(Status));
	ofs.write((const char*)&_id, sizeof(unsigned));
	ofs.write((const char*)&_isInDashboard, sizeof(bool));
}

void Task::readFromFiLe(std::ifstream& ifs)
{
	ifs.read((char*)&_idxOfAuthor, sizeof(unsigned));
	_name = readStringFromFile(ifs);
	_description = readStringFromFile(ifs);
	ifs.read((char*)&_dueDate, sizeof(Date));
	ifs.read((char*)&_status, sizeof(Status));
	ifs.read((char*)&_id, sizeof(unsigned));
	ifs.read((char*)&_isInDashboard, sizeof(bool));
}