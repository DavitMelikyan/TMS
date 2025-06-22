#ifndef TASKMANAGER_H 
#define	TASKMANAGER_H
#include "Headers.h"

class TaskManager {
private:
	std::vector<User*> m_users;
public:
	void register_user();
	User* login();
	void logout();
	void add_task(User& user);
	void delete_task(User& user);
	void edit_task(User& user);
	void display_task(User& user);
	User* findUser(const std::string& name);
	void displayAllTasks();
};

#endif
