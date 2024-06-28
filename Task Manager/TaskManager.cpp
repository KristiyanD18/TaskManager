#include "TaskManager.h"
#include <time.h>
#include <fstream>

int TaskManager::getUserIdx(const MyString& username, const MyString& passsword) const
{
	unsigned usersCount = _users.size();
	for (int i = 0; i < usersCount; i++)
	{
		if (_users[i].isUsername(username) && _users[i].isPassword(passsword))
		{
			return i;
		}
	}
	return -1;
}

int TaskManager::getDashboardIdxByUser(const User*& user) const
{
	unsigned dashboardsCount = _dashboards.size();
	for (int i = 0; i < dashboardsCount; i++)
	{
		if (_dashboards[i].getIdxOfUser() == user->getIdxInSystem())
		{
			return i;
		}
	}
	return -1;
}

void TaskManager::printCountOfUsers() const
{
	std::cout << "Count of users in the system: " << _users.size() << std::endl;
}

void TaskManager::registerUser(const MyString& username, const MyString& password)
{
	srand(time(NULL));
	unsigned id = rand();
	int indexInSystem = _users.size();
	_users.push_back(User(username, password, id, indexInSystem));
	_dashboards.push_back(Dashboard(indexInSystem));
}

void TaskManager::login(const MyString& username, const MyString& password)
{
	int idx = getUserIdx(username, password);
	if (idx == -1)
	{
		throw std::exception("User does not exist!");
	}
	_currentU = &_users[idx];
	_currentD = &_dashboards[idx];
	_currentD->addTasksDueTodayToDashboardAndRemoveOverdued();
}

void TaskManager::logout()
{
	_currentU = nullptr;
	_currentD = nullptr;
}

bool TaskManager::isLoggedIn() const
{
	return _currentU != nullptr;
}

void TaskManager::addTask(const MyString& name, const MyString& desc, const Date& dueDate)
{
	if (_currentD->checkIfTaskExists(_currentU->getIdxInSystem(), name, desc, dueDate))
	{
		std::cout << "This task with the same name already exists!" << std::endl;
	}
	else
	{
		_currentD->addTask(_currentU->getIdxInSystem(), name, desc, dueDate);
		std::cout << "Task added successfully!" << std::endl;
	}
}

void TaskManager::listTasks() const
{
	_currentD->printTasks();
}

void TaskManager::listTasksWithDeadlineTo(const Date& date) const
{
	_currentD->printTasksWithDeadLineTo(date);
}

void TaskManager::updateTaskName(unsigned id, const MyString& newName)
{
	_currentD->getCurrentTaskById(id, _currentT);
	_currentT->setName(newName);
}

void TaskManager::updateTaskDescription(unsigned id, const MyString& newDescription)
{
	_currentD->getCurrentTaskById(id, _currentT);
	_currentT->setDescription(newDescription);
}

void TaskManager::deleteTask(unsigned id)
{
	_currentD->deleteTaskById(id);
}

void TaskManager::startTask(unsigned id)
{
	_currentD->getCurrentTaskById(id, _currentT);
	_currentT->setStatus(Status::IN_PROCESS);
}

void TaskManager::getTask(const MyString& name)
{
	Dashboard* d = _currentD;
	d->sortTasksById();
	d->getCurrentTaskByName(name, _currentT);
	_currentT->printTaskInfo();
}

void TaskManager::getTask(unsigned id)
{
	_currentD->getCurrentTaskById(id, _currentT);
	_currentT->printTaskInfo();
}

void TaskManager::finishTask(unsigned id)
{
	_currentD->getCurrentTaskById(id, _currentT);
	_currentT->setStatus(Status::DONE);
}

void TaskManager::listCompletedTasks() const
{
	_currentD->printCompletedTasks();
}

void TaskManager::removeTaskFromDashboard(unsigned id)
{
	_currentD->getCurrentTaskById(id, _currentT);
	_currentT->setIsInDashboard(0);
}

void TaskManager::addTaskToDashboard(unsigned id)
{
	_currentD->getCurrentTaskById(id, _currentT);
	_currentT->setIsInDashboard(1);
}

void TaskManager::listDashboard() const
{
	_currentD->printTasksInDashboard();
}


void TaskManager::addCol(const MyString& name)
{

}

void TaskManager::deleteCol(const MyString& name)
{

}

void TaskManager::listCols() const
{

}

void TaskManager::addUser(const MyString& colName, const MyString& userName)
{

}

void TaskManager::assignTask(const MyString& colName, const MyString& userName, const Date& dueDate)
{

}

void TaskManager::listColTasks() const
{

}

void TaskManager::exit()
{
	_currentD = nullptr;
	_currentT = nullptr;
	_currentU = nullptr;
}

void TaskManager::writeToFile() const
{
	std::ofstream ofs("TM.dat", std::ios::out | std::ios::binary);

	if (!ofs.is_open())
	{
		throw "Error";
	}

	size_t countOfUsers = _users.size();
	ofs.write((const char*)&countOfUsers, sizeof(size_t));

	for (int i = 0; i < countOfUsers; i++)
	{
		_users[i].writeToFile(ofs);
	}

	size_t countOfDashboards = _dashboards.size();
	ofs.write((const char*)&countOfDashboards, sizeof(size_t));

	for (int i = 0; i < countOfDashboards; i++)
	{
		_dashboards[i].writeToFile(ofs);
	}

	ofs.clear();
	ofs.close();
}

void TaskManager::readFromFiLe()
{
	std::ifstream ifs("TM.dat", std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		throw "Error";
	}

	size_t countOfUsers = 0;
	ifs.read((char*)&countOfUsers, sizeof(size_t));

	for (int i = 0; i < countOfUsers; i++)
	{
		User user;
		user.readFromFiLe(ifs);
		_users.push_back(user);
	}

	size_t countOfDashboards = 0;
	ifs.read((char*)&countOfDashboards, sizeof(size_t));

	for (int i = 0; i < countOfDashboards; i++)
	{
		Dashboard dashboard;
		dashboard.readFromFiLe(ifs);
		_dashboards.push_back(dashboard);
	}

	ifs.clear();
	ifs.close();
}

TaskManager::~TaskManager()
{
	writeToFile();
}