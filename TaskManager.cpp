#include "Headers.h"

void TaskManager::register_user() {
    std::string name;
    std::string passwd;
    std::cout << "Enter the username: ";
    std::cin >> name;
    std::cout << "Enter the password: ";
    std::cin >> passwd;
    m_users.emplace_back(new User(name, passwd));
}

User* TaskManager::login() {
    std::string name;
    std::string passwd;
    std::cout << "Enter the username: ";
    std::cin >> name;
    std::cout << "Enter the password: ";
    std::cin >> passwd;
    User* user = findUser(name);
    if (user && user->passwordCheck(passwd)) {
        user->login();
        std::cout << "User logged in successfully\n";
        return user;
    }
    std::cout << "Invalid user or password\n";
    return nullptr;
}

void TaskManager::logout() {
    std::string name;
    std::string passwd;
    std::cout << "Enter the username: ";
    std::cin >> name;
    std::cout << "Enter the password: ";
    std::cin >> passwd;
    User* user = findUser(name);
    if (user && user->passwordCheck(passwd)) {
        user->logout();
        std::cout << "You logged out successfully\n";
        return;
    }
    std::cout << "Invalid username or password.\n";
}

void TaskManager::add_task(User& user) {
    Task* newTask = new Task;
    std::cin >> *newTask;
    newTask->setUId(user.getId());
    user.addTask(newTask);
}

void TaskManager::delete_task(User& user) {
    std::string title;
    std::cout << "Enter the title of the task: ";
    std::cin >> title;
    user.deleteTask(title);
}

void TaskManager::edit_task(User& user) {
    Task* newTask = new Task;
    std::string title;
    std::cout << "Enter the title of the task: ";
    std::cin >> title;
    std::cin >> *newTask;
    user.editTask(title, *newTask);
}

void TaskManager::display_task(User& user) {
    std::string title;
    std::cout << "Enter the title of the task: ";
    std::cin >> title;
    user.displayTask(title);
}

User* TaskManager::findUser(const std::string& name) {
    int size = m_users.size();
    for (int i = 0; i < size; ++i) {
        if (m_users[i]->getName()  == name) {
            return m_users[i];
        }
    }
    std::cout << "User not found\n";
    return nullptr;
}

void TaskManager::displayAllTasks() {
    int size = m_users.size();
    for (int i = 0; i < size; ++i) {
        m_users[i]->listTasks();
        std::cout << std::endl;
    }
}