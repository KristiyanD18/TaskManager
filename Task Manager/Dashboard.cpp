#include "Dashboard.h"
#include <time.h>
#include <fstream>
#include "SerializeFunctions.h"

int Dashboard::getTaskIdxByName(const MyString& name) const
{
	size_t count = _tasks.size();
	for (int i = 0; i < count; i++)
	{
		if (_tasks[i].getName() == name)
		{
			return i;
		}
	}
	return -1;
}

int Dashboard::getTaskIdxById(unsigned id) const
{
	size_t count = _tasks.size();
	for (int i = 0; i < count; i++)
	{
		if (_tasks[i].getId() == id)
			return i;
	}
	return -1;
}

Dashboard::Dashboard(unsigned idxOfAuthor)
{
	
	_idxOfUser = idxOfAuthor;
}

void Dashboard::addTask(unsigned idxOfAuthor, const MyString& name, const MyString& description, const Date& dueDate)
{
	srand(time(NULL));
	unsigned id = rand();
	_tasks.push_back(Task(idxOfAuthor, id, name, dueDate, Status::ON_HOLD, description));
}

void Dashboard::deleteTaskById(unsigned id)
{
	int idx = getTaskIdxById(id);
	if (idx == -1)
	{
		throw std::invalid_argument("No such task exists");
	}

	_tasks.erase(idx);
}

void Dashboard::printTasks() const
{
	size_t count = _tasks.size();

	if (count == 0)
	{
		std::cout << "You have 0 tasks currently :(" << std::endl;
		return;
	}

	for (int i = 0; i < count; i++)
	{
		_tasks[i].printTaskInfo();
	}
}

void Dashboard::addTasksDueTodayToDashboardAndRemoveOverdued()
{
	int countOfTasks = _tasks.size();

	Date date;
	date.setDateToToday();

	for (size_t i = 0; i < countOfTasks; i++)
	{
		if (_tasks[i].getDueDate() == date)
		{
			_tasks[i].setIsInDashboard(1);
		}

		if (date > _tasks[i].getDueDate())
		{
			_tasks[i].setIsInDashboard(0);
		}
	}
}

bool Dashboard::checkIfTaskExists(unsigned idxInSystem, const MyString& name, const MyString& desc, const Date& dueDate) const
{
	int countOfTasks = _tasks.size();

	for (size_t i = 0; i < countOfTasks; i++)
	{
		if (_tasks[i].getName() == name && _tasks[i].getDescription() == desc && _tasks[i].getDescription() == desc && _tasks[i].getDueDate() == dueDate)
		{
			return true;
		}
	}
	return false;
}

void Dashboard::printCompletedTasks() const
{
	size_t count = _tasks.size();

	std::cout << "--------------COMPLETED TASKS--------------" << std::endl;
	for (int i = 0; i < count; i++)
	{
		if (_tasks[i].getStatus() == Status::DONE)
		{
			_tasks[i].printTaskInfo();
		}
	}
	std::cout << "-------------------------------------------" << std::endl;
}

void Dashboard::printTasksWithDeadLineTo(const Date& date) const
{
	size_t count = _tasks.size();

	for (size_t i = 0; i < count; i++)
	{
		if (_tasks[i].getDueDate() == date)
		{
			_tasks[i].printTaskInfo();
		}
	}
}

unsigned Dashboard::getIdxOfUser() const
{
	return _idxOfUser;
}

void Dashboard::printTasksInDashboard() const
{
	unsigned tasksCount = _tasks.size();

	std::cout << "--------------DASHBOARD--------------" << std::endl;

	for (int i = 0; i < tasksCount; i++)
	{
		if (_tasks[i].isInDashboard())
		{
			std::cout << "here ";
			_tasks[i].printTaskInfo();
		}
	}
	std::cout << "-------------------------------------" << std::endl;
}

void Dashboard::getCurrentTaskByName(const MyString& name, Task*& currentTask)
{
	int idx = getTaskIdxByName(name);
	if (idx == -1)
	{
		throw std::invalid_argument("No such task exists");
	}

	currentTask = &_tasks[idx];
}

void Dashboard::getCurrentTaskById(unsigned id, Task*& currentT)
{
	int idx = getTaskIdxById(id);
	if (idx == -1)
	{
		throw std::invalid_argument("No such task exists");
	}

	currentT = &_tasks[idx];
}

unsigned Dashboard::getCountOfTasks()
{
	return _tasks.size();
}

void Dashboard::sortTasksById()
{
	int n = _tasks.size();
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (_tasks[j].getId() > _tasks[j+1].getId())
			{
				Task task = _tasks[j];
				_tasks[j] = _tasks[j + 1];
				_tasks[j + 1] = task;
			}
		}
	}
}

void Dashboard::writeToFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&_idxOfUser, sizeof(unsigned));

	size_t countOfTasks = _tasks.size();
	ofs.write((const char*)&countOfTasks, sizeof(size_t));

	for (int i = 0; i < countOfTasks; i++)
	{
		_tasks[i].writeToFile(ofs);
	}
}

void Dashboard::readFromFiLe(std::ifstream& ifs)
{
	ifs.read((char*)&_idxOfUser, sizeof(unsigned));

	size_t countOfTasks;
	ifs.read((char*)&countOfTasks, sizeof(size_t));

	for (int i = 0; i < countOfTasks; i++)
	{
		Task task;
		task.readFromFiLe(ifs);
		_tasks.push_back(task);
	}
}
