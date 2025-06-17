#ifndef TASK_H
#define TASK_H
#include "Headers.h"

enum class Priority {
	LOW, MEDIUM, HIGH, URGENT
};

enum class Status {
	NOT_STARTED, IN_PROGRESS, COMPLETED 
};

class Task {
private:
	static int m_taskidcount;
	std::string m_title;
	std::string m_description;
	std::string m_deadline;
	std::string m_category;
	std::string m_task_id;
	std::string m_uid;
	Status m_status;
	Priority m_priority;
public:
	Task();
	Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, Priority priority, Status status, const std::string& m_uid);
	Task(const Task& other);
	Task& operator=(const Task& other);
	Task(Task&& other) noexcept;
	Task& operator=(Task&& other) noexcept;
	~Task(); 

	void editTask(const Task& task);

	const std::string& getTaskId() const;
	const std::string& getTitle() const;
	const std::string& getDescription() const;
	const std::string& getDeadline() const;
	const std::string& getCategory() const;
	const std::string& getUId() const;
	const Priority& getPriority() const;
	const Status& getStatus() const;
	
	void setTaskId(const std::string& taskID);
	void setTitle(const std::string& title);
	void setDescription(const std::string& desription);
	void setDeadline(const std::string& deadline);
	void setCategory(const std::string& category);
	void setUId(const std::string& uid);
	void setPriority(const Priority priority); 
	void setStatus(const Status status);

	friend std::istream& operator>>(std::istream& os, Priority& priority);
	friend std::ostream& operator<<(std::ostream& os, const Priority priority);
	friend std::istream& operator>>(std::istream& os, Status& status);
	friend std::ostream& operator<<(std::ostream& os, const Status status);
	friend std::istream& operator>>(std::istream& os, Task& task);
	friend std::ostream& operator<<(std::ostream& os, const Task task);

	bool operator==(const Task& other) const;
    	bool operator!=(const Task& other) const;
    	bool operator<(const Task& other) const;
    	bool operator>(const Task& other) const;

    	Task& operator++();    
    	const Task operator++(int);  
    	Task& operator--();    
    	const Task operator--(int); 
};
	
#endif
