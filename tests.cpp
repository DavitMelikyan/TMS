#include <gtest/gtest.h>
#include "Headers.h"

TEST(UserTest, UserCtor) {
    	User user("Davit", "password123");
    	EXPECT_EQ(user.getName(), "Davit");
    	EXPECT_TRUE(user.passwordCheck("password123"));
}

TEST(UserTest, TaskAddSrch) {
    	User user("Davit", "123");
    	Task* task = new Task("Title", "Desc", "31-06-2025", "Work", Priority::HIGH, Status::NOT_STARTED, user.getId());
    	user.addTask(task);
    	Task* found = user.searchTask("Title");
    	ASSERT_NE(found, nullptr);
    	EXPECT_EQ(found->getTitle(), "Title");
}

TEST(UserTest, TaskEditDlt) {
    	User user("Username", "abc");
    	Task* task = new Task("abc", "def", "ghi", "jkl", Priority::LOW, Status::NOT_STARTED, user.getId());
    	user.addTask(task);
    	Task updated("A", "Upd", "11-11-2111", "Upd", Priority::URGENT, Status::IN_PROGRESS, user.getId());
    	user.editTask("abc", updated);
    	Task* found = user.searchTask("A");
    	ASSERT_NE(found, nullptr);
    	EXPECT_EQ(found->getDescription(), "Upd");
    	user.deleteTask("A");
    	EXPECT_EQ(user.searchTask("A"), nullptr);
}

TEST(UserTest, CopyCtor) {
    	User user1("Davit", "xyz");
    	Task* task = new Task("A", "Test", "31-12-2999", "Test", Priority::HIGH, Status::IN_PROGRESS, user1.getId());
    	user1.addTask(task);
    	User user2 = user1;
    	Task* found = user2.searchTask("A");
    	ASSERT_NE(found, nullptr);
    	EXPECT_EQ(found->getTitle(), "A");
    	user1.searchTask("A")->setTitle("newA");
    	EXPECT_EQ(user2.searchTask("A")->getTitle(), "A");
}

TEST(TaskTest, TaskCtor) {
    	Task task("Title", "Description", "01-07-2025", "Work", Priority::MEDIUM, Status::NOT_STARTED, "ID1");
    	EXPECT_EQ(task.getTitle(), "Title");
    	EXPECT_EQ(task.getDescription(), "Description");
    	EXPECT_EQ(task.getDeadline(), "01-07-2025");
    	EXPECT_EQ(task.getCategory(), "Work");
    	EXPECT_EQ(task.getPriority(), Priority::MEDIUM);
    	EXPECT_EQ(task.getStatus(), Status::NOT_STARTED);
    	EXPECT_EQ(task.getUId(), "ID1");
}

TEST(TaskTest, IncDec) {
    	Task task("A", "B", "C", "D", Priority::LOW, Status::NOT_STARTED, "U1");
    	++task;
    	EXPECT_EQ(task.getStatus(), Status::IN_PROGRESS);
    	Task tmp = task++;
    	EXPECT_EQ(task.getStatus(), Status::COMPLETED);
    	EXPECT_EQ(tmp.getStatus(), Status::IN_PROGRESS);
	--task;
    	EXPECT_EQ(task.getStatus(), Status::IN_PROGRESS);
	Task tmp2 = task--;
	EXPECT_EQ(task.getStatus(), Status::NOT_STARTED);
	EXPECT_EQ(tmp2.getStatus(), Status::IN_PROGRESS);
}

TEST(TaskTest, Comp) {
    Task tlow("Low", "A", "B", "C", Priority::LOW, Status::NOT_STARTED, "1");
    Task thigh("High", "D", "E", "F", Priority::HIGH, Status::NOT_STARTED, "1");

    EXPECT_TRUE(tlow < thigh);
    EXPECT_TRUE(thigh > tlow);
    EXPECT_TRUE(tlow != thigh);
}
