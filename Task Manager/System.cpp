#include "System.h"
#include "TaskManager.h"
#include "HelperFunctions.h"

void run()
{
	TaskManager s;
	s.readFromFiLe();

	s.printCountOfUsers(); // additional function

	std::cout << "Register or login: ";
	while (true)
	{
		MyString command;
		std::cin >> command;

		if (command == "register")
		{
			std::cout << "Enter username: ";
			MyString username, password;
			std::cin >> username;

			std::cout << "Enter password: ";
			std::cin >> password;

			s.registerUser(username, password); // register logic

			std::cout << "Registered successfully!" << std::endl;
		}
		else if (command == "login")
		{
			std::cout << "Enter username: ";
			MyString username, password;
			std::cin >> username;

			std::cout << "Enter password: ";
			std::cin >> password;

			s.login(username, password); // login logic

			std::cout << "Welcome back, " << username << "!" << std::endl;
			continue;
		}

		if (s.isLoggedIn())
		{
			if (command == "add-task")
			{
				std::cout << "Enter name: ";
				char buff[1024];
				std::cin.ignore();
				std::cin.getline(buff, 1024);
				MyString name = buff;

				std::cout << "Enter description: ";
				std::cin.getline(buff, 1024);
				MyString description = buff;

				std::cout << "Enter due date (YYYY-MM-DD): ";
				Date dueDate;
				dueDate.readDate();

				s.addTask(name, description, dueDate); // add task logic and prints
			}
			else if (command == "update-task-name")
			{
				std::cout << "Enter id: ";
				unsigned id;
				std::cin >> id;

				std::cout << "Enter new name: ";
				char buff[1024];
				std::cin.ignore();
				std::cin.getline(buff, 1024);
				MyString name = buff;

				s.updateTaskName(id, name); // update task name logic
				std::cout << "Task name updated successfully!" << std::endl;
			}
			else if (command == "start-task")
			{
				unsigned id;
				std::cout << "Enter id: ";
				std::cin >> id;
				s.startTask(id);

				std::cout << "Task started successfully!" << std::endl;
			}
			else if (command == "update-task-description")
			{
				std::cout << "Enter id: ";
				unsigned id;
				std::cin >> id;

				std::cout << "Enter new description: ";
				char buff[1024];
				std::cin.ignore();
				std::cin.getline(buff, 1024);
				MyString description = buff;

				s.updateTaskDescription(id, description); // update description name logic
				std::cout << "Task description updated successfully!" << std::endl;
			}
			else if (command == "add-task-to-dashboard")
			{
				std::cout << "Enter id: ";
				unsigned id;
				std::cin >> id;

				s.addTaskToDashboard(id); // add task to dashboard logic
				std::cout << "Task added to dashboard successfully!" << std::endl;
			}
			else if (command == "remove-task-from-dashboard")
			{
				std::cout << "Enter id: ";
				unsigned id;
				std::cin >> id;

				s.removeTaskFromDashboard(id); // remove task from dashborad logic
				std::cout << "Task removed from dashboard successfully!" << std::endl;
			}
			else if (command == "list-dashboard")
			{
				s.listDashboard();
			}
			else if (command == "delete-task")
			{
				std::cout << "Enter id: ";
				unsigned id;
				std::cin >> id;

				s.deleteTask(id); // delete task logic

				std::cout << "Task deleted successfully!" << std::endl;
			}
			else if (command == "get-task")
			{
				std::cout << "Choose how to find the task: " << std::endl;
				std::cout << "id - search for task by id " << std::endl;
				std::cout << "name - search for task by name " << std::endl;

				std::cin >> command;
				if (command == "id")
				{
					std::cout << "Enter id: ";
					unsigned id;
					std::cin >> id;
					s.getTask(id); // and prints it
				}
				else if (command == "name")
				{
					std::cout << "Enter name: ";
					char buff[1024];
					std::cin.ignore();
					std::cin.getline(buff, 1024);
					MyString description = buff;
					MyString name = buff;
					s.getTask(name); // and prints it
				}
				else
				{
					std::cout << "Invalid command!" << std::endl;
				}
			}
			else if (command == "list-tasks")
			{
				std::cout << "Choose which tasks to be shown: " << std::endl;
				std::cout << "all - show all tasks" << std::endl;
				std::cout << "date - show tasks with deadline specific day" << std::endl;

				std::cin >> command;
				if (command == "all")
				{
					s.listTasks();
				}
				else if (command == "date")
				{
					std::cout << "Enter due date (YYYY-MM-DD): ";
					Date date;
					date.readDate();
					s.listTasksWithDeadlineTo(date);
				}
				else
				{
					std::cout << "Invalid command!" << std::endl;
				}
			}
			else if (command == "list-completed-tasks")
			{
				s.listCompletedTasks();
			}
			else if (command == "finish-task")
			{
				std::cout << "Enter id: ";
				unsigned id;
				std::cin >> id;

				s.finishTask(id); // finish task logic

				std::cout << "Congratulations on completing the task!" << std::endl;
			}
			else if (command == "logout")
			{
				s.logout(); // logout logic
				std::cout << "Logged out successfully!" << std::endl;
			}
			else if (command == "exit")
			{
				s.exit(); // exit logic
				std::cout << "Exited successfully!" << std::endl;
				break;
			} // ---------------------------------COLABORATIONS---------------------------------
			else if (command == "add-collaboration")
			{
				MyString name;
				std::cout << "Enter name: ";
				std::cin >> name;

				s.addCol(name);  // add collaboration logic

				std::cout << "Collaboration added successfully!" << std::endl;
			}
			else if (command == "delete-collaboration")
			{
				MyString name;
				std::cout << "Enter name: ";
				std::cin >> name;

				s.deleteCol(name); // delete collaboration logic

				std::cout << "Collaboration deleted successfully!" << std::endl;
			}
			else if (command == "list-collaborations")
			{
				s.listCols();// print collaboration logic
			}
			else if (command == "add-user")
			{
				MyString colName, userName;
				std::cout << "Enter collaboration name: ";
				std::cin >> colName;

				std::cout << "Enter name of user: ";
				std::cin >> userName;

				s.addUser(colName, userName); // add user logic
				std::cout << "User added to collaboration successfully!" << std::endl;
			}
			else if (command == "assign-task")
			{
				MyString colName, userName;
				std::cout << "Enter collaboration name: ";
				std::cin >> colName;

				std::cout << "Enter name of user: ";
				std::cin >> userName;

				std::cout << "Enter due date (YYYY-MM-DD): ";
				Date dueDate;
				dueDate.readDate();

				s.assignTask(colName, userName, dueDate); // assign-task logic
				std::cout << "Task assigned succesfully!" << std::endl;
			}
			else if (command == "list-tasks")
			{
				MyString colName;
				std::cout << "Enter collaboration name: ";
				std::cin >> colName;

				s.listColTasks(); // print col tasks logic
			}
			else
			{
				std::cout << "This command is not valid!" << std::endl;
			}
		}
		else
		{
			throw "Not logged in!";
		}
	}
}