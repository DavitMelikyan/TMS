#include "Headers.h"

int Task::m_taskidcount = 0;

Task::Task() : m_title{"Unknown"}, m_description{"Empty"}, m_deadline{"Unknown"}, m_category{"Unknown"}, m_priority{Priority::LOW}, m_status{Status::NOT_STARTED} {
	m_task_id = "TID" + std::to_string(m_taskidcount++);
}

Task::Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, Priority priority, Status status, const std::string& uid) : m_title(title), m_description(description), m_deadline(deadline), m_category(category),m_priority(priority), m_status(status), m_uid(uid) {
	m_task_id = "TID" + std::to_string(m_taskidcount++);
}       

Task::Task(const Task& other) : m_title(other.m_title), m_description(other.m_description), m_deadline(other.m_deadline), m_category(other.m_category),m_task_id(other.m_task_id), m_uid(other.m_uid), m_status(other.m_status), m_priority(other.m_priority) {} 
        
Task::Task(Task&& other) noexcept : m_title(std::move(other.m_title)), m_description(std::move(other.m_description)), m_deadline(std::move(other.m_deadline)), m_category(std::move(other.m_category)), m_task_id(std::move(other.m_task_id)), m_uid(std::move(other.m_uid)), m_status(std::move(other.m_status)), m_priority(std::move(other.m_priority)) {}
        
Task::~Task() = default;

void Task::editTask(const Task& task) {
	setTitle(task.m_title);
	setDescription(task.m_description);
	setDeadline(task.m_deadline);
	setCategory(task.m_category);
    	setStatus(task.m_status);
	setPriority(task.m_priority);
}

const std::string& Task::getTaskId() const { 
	return m_task_id; 
}

const std::string& Task::getTitle() const {
	return m_title; 
}

const std::string& Task::getDescription() const {
	return m_description; 
}

const std::string& Task::getDeadline() const { 
	return m_deadline; 
}

const std::string& Task::getCategory() const { 
	return m_category; 
}

const std::string& Task::getUId() const { 
	return m_uid; 
}

const Priority& Task::getPriority() const { 
	return m_priority; 
}

const Status& Task::getStatus() const { 
	return m_status; 
}


void Task::setTaskId(const std::string& id) { 
	m_task_id = id; 
}

void Task::setTitle(const std::string& title) { 
	m_title = title; 
}

void Task::setDeadline(const std::string& deadline) { 
	m_deadline = deadline; 
}

void Task::setDescription(const std::string& desc) { 
	m_description = desc; 
}

void Task::setCategory(const std::string& category) { 
	m_category = category; 
}

void Task::setUId(const std::string& uid) { 
	m_uid = uid; 
}

void Task::setStatus(const Status status) {
	m_status = status;
}   

void Task::setPriority(const Priority priority) {
	m_priority = priority;
}
       
std::istream& operator>>(std::istream& is, Priority& priority) {
	int value = 0;
    	is >> value;
	while (value < 0 || value > 2) {
		std::cout << "You entered wrong value, try again: ";
		is >> value;
	}
    	priority = static_cast<Priority>(value);
    	return is;
}

std::ostream& operator<<(std::ostream& os, const Priority priority) {
	switch (priority) {
        case Priority::LOW:
		os << "Low"; 
		break;
	case Priority::MEDIUM: 
		os << "Medium"; 
		break;
        case Priority::HIGH: 
		os << "High"; 
		break;
        case Priority::URGENT: 
		os << "Urgent"; 
		break;
    	}
    	return os;
}

std::istream& operator>>(std::istream& is, Status& status) {
	int value = 0;
	is >> value;
	while (value < 0 || value > 3) {
		std::cout << "You entered wrong value, try again: ";
		is >> value;
	}
    	status = static_cast<Status>(value);
   	return is;
}

std::ostream& operator<<(std::ostream& os, const Status status) {
	switch (status) {
        case Status::NOT_STARTED: 
		os << "Not Started"; 
		break;
        case Status::IN_PROGRESS: 
		os << "In Progress"; 
		break;
        case Status::COMPLETED: 
		os << "Completed"; 
		break;
    	}
    	return os;
}

std::istream& operator>>(std::istream& is, Task& task) {
	std::string title;
	std::string description;
	std::string deadline;
	std::string category;
    	int priority = 0;
	int status = 0;
    	std::cout << "Enter the task title: ";
    	is >> title;
    	std::cout << "Enter the task description: ";
    	is >> description;
    	std::cout << "Enter the task deadline: ";
    	is >> deadline;
    	std::cout << "Enter the task category: ";
    	is >> category;
    	std::cout << "Enter priority (0 - Low, 1 - Medium, 2 - High, 3 - Urgent): ";
    	is >> priority;
    	std::cout << "Enter status (0 - Not Started, 1 - In Progress, 2 - Completed): ";
    	is >> status;
    	task.setTitle(title);
    	task.setDescription(description);
    	task.setDeadline(deadline);
   	task.setCategory(category);
   	task.setPriority(static_cast<Priority>(priority));
   	task.setStatus(static_cast<Status>(status));
    	return is;
}

std::ostream& operator<<(std::ostream& os, const Task task) {
	os << "Task ID: " << task.m_task_id << std::endl<< "Title: " << task.m_title << std::endl << "Description: " << task.m_description << std::endl << "Deadline: " << task.m_deadline << std::endl << "Category: " << task.m_category << std::endl << "Status: " << task.m_status << std::endl << "Priority: " << task.m_priority << std::endl << "User ID: " << task.m_uid;
 	return os;
}

bool Task::operator==(const Task& other) const {
	return m_task_id == other.m_task_id;
}

bool Task::operator!=(const Task& other) const {
	return !(m_task_id == other.m_task_id);
}

bool Task::operator<(const Task& other) const {
	return static_cast<int>(m_priority) < static_cast<int>(other.m_priority);
}

bool Task::operator>(const Task& other) const {
	return static_cast<int>(m_priority) > static_cast<int>(other.m_priority);
}

Task& Task::operator++() {
	if (m_status != Status::COMPLETED) {
        	m_status = static_cast<Status>(static_cast<int>(m_status) + 1);
    	}
    	return *this;
}   

const Task Task::operator++(int) {
	Task tmp = *this;
	if (m_status != Status::COMPLETED) {
        	m_status = static_cast<Status>(static_cast<int>(m_status) + 1);
    	}
   	return tmp;
}  

Task& Task::operator--() {
	if (m_status != Status::NOT_STARTED) {
        	m_status = static_cast<Status>(static_cast<int>(m_status) - 1);
    	}
	return *this;
}   

const Task Task::operator--(int) {
	Task tmp = *this;
	if (m_status != Status::NOT_STARTED) {
        	m_status = static_cast<Status>(static_cast<int>(m_status) - 1);
  	}
	return tmp;
} 
