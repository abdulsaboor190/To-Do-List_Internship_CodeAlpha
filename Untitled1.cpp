#include <iostream>
#include <string>

using namespace std;

class Task {
    string description;
    bool completed;

public:
    Task(string desc) : description(desc), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() {
        return completed;
    }

    string getDescription() {
        return description;
    }
};

class ToDoList {
    Task* tasks[100];
    int taskCount;

public:
    ToDoList() : taskCount(0) {}

    void addTask(string desc) {
        if (taskCount < 100) {
            tasks[taskCount++] = new Task(desc);
        } else {
            cout << "Task list is full" << endl;
        }
    }

    void viewTasks() {
        cout << "\n----- To-Do List -----\n";
        if (taskCount == 0) {
            cout << "No tasks in the list.\n";
        } else {
            for (int i = 0; i < taskCount; ++i) {
                cout << i + 1 << ". " << tasks[i]->getDescription() << " [" << (tasks[i]->isCompleted() ? "Completed" : "Pending") << "]" << endl;
            }
        }
        cout << "----------------------\n";
    }

    void markTaskCompleted(int index) {
        if (index > 0 && index <= taskCount) {
            tasks[index - 1]->markCompleted();
            cout << "Task " << index << " marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }

    void removeTask(int index) {
        if (index > 0 && index <= taskCount) {
            delete tasks[index - 1];
            for (int i = index; i < taskCount; ++i) {
                tasks[i - 1] = tasks[i];
            }
            --taskCount;
            cout << "Task " << index << " removed from the list.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }

    ~ToDoList() {
        for (int i = 0; i < taskCount; ++i) {
            delete tasks[i];
        }
    }
};

void showMenu() {
    cout << "\n------ To-Do List Menu ------\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "-----------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    ToDoList list;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string desc;
                cout << "Enter task description: ";
                getline(cin, desc);
                list.addTask(desc);
                break;
            }
            case 2: {
                list.viewTasks();
                break;
            }
            case 3: {
                int index;
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                list.markTaskCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task number to remove: ";
                cin >> index;
                list.removeTask(index);
                break;
            }
            case 5: {
                cout << "Exiting the application.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }

    } while (choice != 5);

    return 0;
}
