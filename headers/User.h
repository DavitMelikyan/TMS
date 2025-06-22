#ifndef USER_H
#define USER_H
#include "Headers.h"

class User {
private:
	static int m_idcount;
	std::string m_id;
	std::string m_name;
	std::string m_passwd;
	std::vector<Task*> m_tasks;
	bool is_logged;
public:
	User(const std::string& username, const std::string& password);
	User(const User& other);
	User& operator=(const User& other);
	User(User&& other) noexcept;
	User& operator=(User&& other) noexcept;
	~User();
	const std::string& getId() const;
	const std::string& getName() const;
	void addTask(Task* task);
	void deleteTask(const std::string& title);
	void editTask(const std::string& title, const Task& updatedTask);
	void listTasks() const;
	Task* searchTask(const std::string& title);
	Task* searchTaskById(const std::string& id);
	bool passwordCheck(const std::string& passwd);
	void login(); 
	void logout();
	void displayTask(const std::string& title);
	bool operator==(const User& other) const;
	bool operator!=(const User& other) const;
	operator bool() const;
	friend std::ostream& operator<<(std::ostream& os, const User& user);
	friend std::istream& operator>>(std::istream& is, User& user);
};

#endif
