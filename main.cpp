#include "Headers.h"

void displayMainMenu() {
    	std::cout << "1. Register\n";
    	std::cout << "2. Login\n";
    	std::cout << "3. Logout\n";
    	std::cout << "4. Add Task\n";
    	std::cout << "5. Edit Task\n";
    	std::cout << "6. Delete Task\n";
    	std::cout << "7. Display Task\n";
    	std::cout << "8. Display All Tasks\n";
	std::cout << "9. Exit\n";
    	std::cout << "Choose an option: ";
}

int main(int argc, char** argv) {
     	std::cout << "Welcome to the Task Management System!\n";
    	TaskManager manager;
    	User* user = nullptr;
    	int choice = 0;
    	while (true) {
		displayMainMenu();
        	std::cin >> choice;
        	switch (choice) {
            		case 1:
                		manager.register_user();
                		break;
            	case 2:
                	user = manager.login();
                	break;
            	case 3:
                	manager.logout();
                	user = nullptr;
               		break;
            	case 4:
                	if (user) {
                    		manager.add_task(*user);
                	} else {
                    		std::cout << "You are not logged in\n";
                	}
                	break;
            	case 5:
                	if (user) {
                    		manager.edit_task(*user);
                	} else {
                    		std::cout << "You are not logged in\n";
                	}
                	break;
            	case 6:
                	if (user) {
                    		manager.delete_task(*user);
                	} else {
                    		std::cout << "You are not logged in\n";
                	}
                	break;
            	case 7:
                	if (user) {
                    		manager.display_task(*user);
                	} else {
                    		std::cout << "You are not logged in\n";
               		}
                	break;
            	case 8:
                	manager.displayAllTasks();
               		break;
            	case 9:
                	std::cout << "Task Managment System closed\n";
                	return 0;
            	default:
                	std::cout << "Invalid option\n";
        	}
    	}
	::testing::InitGoogleTest(&argc, argv);
    	return RUN_ALL_TESTS();
}
