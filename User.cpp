#include "Headers.h"

int User::m_idcount = 0;

User::User(const std::string& username, const std::string& password) : m_name{username}, m_passwd{password},  is_logged{false} {
	m_id = "ID" + std::to_string(m_idcount++);
}

User::User(const User& other) : m_name{other.m_name}, m_id{other.m_id}, m_passwd{other.m_passwd}, is_logged{other.is_logged} {
    	int otherSize = other.m_tasks.size();
	for (int i = 0; i < otherSize; ++i) {
        	m_tasks.push_back(new Task(*other.m_tasks[i]));
    	}
}

User& User::operator=(const User& other) {
    	if (this == &other) {
		return *this;
	}
    	for (int i = 0; i < m_tasks.size(); ++i) {
        	delete m_tasks[i];
    	}
    	m_tasks.clear();
    	m_id = other.m_id;
    	m_name = other.m_name;
    	m_passwd = other.m_passwd;
    	is_logged = other.is_logged;
    	for (int i = 0; i < other.m_tasks.size(); ++i) {
        	m_tasks.push_back(new Task(*other.m_tasks[i]));
    	}
    	return *this;
}

User::User(User&& other) noexcept : m_id{std::move(other.m_id)}, m_name{std::move(other.m_name)}, m_passwd{std::move(other.m_passwd)}, m_tasks{std::move(other.m_tasks)}, is_logged{other.is_logged} {
	other.m_tasks.clear();
}

User& User::operator=(User&& other) noexcept {
    	if (this == &other) {
		return *this;
	}
    	for (int i = 0; i < m_tasks.size(); ++i) {
        	delete m_tasks[i];
    	}
    	m_tasks = std::move(other.m_tasks);
    	m_id = std::move(other.m_id);
    	m_name = std::move(other.m_name);
    	m_passwd = std::move(other.m_passwd);
    	is_logged = other.is_logged;
	other.is_logged = false;
    	other.m_tasks.clear();
    	return *this;
}


User::~User() {
	int size = m_tasks.size();
	for (int i = 0; i < size; ++i) {
		delete m_tasks[i];
	}
	m_tasks.clear();
}

const std::string& User::getId() const { 
	return m_id; 
}

const std::string& User::getName() const { 
	return m_name; 
}

void User::addTask(Task* task) {
	m_tasks.push_back(task);
}

void User::deleteTask(const std::string& title) {
	int size = m_tasks.size();
	for (int i = 0; i < size; ++i) {
		if (m_tasks[i]->getTitle() == title) {
			delete m_tasks[i];
			m_tasks.erase(m_tasks.begin() + i);
			return;
		}
	}
	std::cout << "Task not found\n";
}
void User::editTask(const std::string& title, const Task& updatedTask) {
	Task* task = searchTask(title);
	if (task) {
		task->editTask(updatedTask);
		return;
	}
	std::cout << "Task not found\n";
}
        
void User::listTasks() const {
	int size = m_tasks.size();
	for (int i = 0; i < size; ++i) {
		std::cout << *m_tasks[i] << std::endl;
	}
}
 
Task* User::searchTask(const std::string& title) {
	int size = m_tasks.size();
	for (int i = 0; i < size; ++i) {
        	if (m_tasks[i]->getTitle() == title) {
			return m_tasks[i];
		}
	}
	std::cout << "Task not found\n";
	return nullptr;
}

Task* User::searchTaskById(const std::string& id) {
	int size = m_tasks.size();
	for (int i = 0; i < size; ++i) {
		if (m_tasks[i]->getTaskId() == id) {
			return m_tasks[i];
		}
	}
	std::cout << "Task not found\n";
	return nullptr;
}

bool User::passwordCheck(const std::string& passwd) {
	return passwd == m_passwd;
}

void User::login() {
	is_logged = true;
}

void User::logout() {
	is_logged = false;	
}

void User::displayTask(const std::string& title) {
    Task* task = searchTask(title);
	if (task) {
		std::cout << *task << std::endl;
	}
}

bool User::operator==(const User& other) const {
    	return m_id == other.m_id;
}

bool User::operator!=(const User& other) const {
    	return !(*this == other);
}

User::operator bool() const {
    	return is_logged;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    	os << "Username: " << user.m_name << std::endl << "User ID: " << user.m_id << std::endl << "Is logged: " << user.is_logged;
    	return os;
}

std::istream& operator>>(std::istream& is, User& user) {
    	std::cout << "Enter username: ";
    	is >> user.m_name;
    	std::cout << "Enter password: ";
    	is >> user.m_passwd;
    	return is;
}
