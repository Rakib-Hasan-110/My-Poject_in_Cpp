#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task
{
private:
    string description;
    bool completed;

public:
    
    Task(string desc) : description(desc), completed(false) {}

   
    void markCompleted()
    {
        completed = true;
    }

   
    bool isCompleted() const
    {
        return completed;
    }

    
    string getDescription() const
    {
        return description;
    }
};


class ToDoList
{
private:
    vector<Task> tasks;

public:
   
    void addTask(const string &description)
    {
        tasks.push_back(Task(description));
    }

   
    void completeTask(int taskIndex)
    {
        if (taskIndex < 0 || taskIndex >= tasks.size())
        {
            cout << "Invalid task number!" << endl;
        }
        else
        {
            tasks[taskIndex].markCompleted();
            cout << "Task " << taskIndex + 1 << " marked as completed." << endl;
        }
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "No tasks in the list!" << endl;
        }
        else
        {
            cout << "To-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); i++)
            {
                cout << i + 1 << ". " << tasks[i].getDescription()
                     << " [" << (tasks[i].isCompleted() ? "Completed" : "Not Completed") << "]" << endl;
            }
        }
    }
};

int main()
{
    ToDoList myList;
    int choice;

    while (true)
    {
        cout << "\n1. Add Task\n2. Complete Task\n3. View Tasks\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            cin.ignore(); // Clear input buffer
            string taskDescription;
            cout << "Enter task description: ";
            getline(cin, taskDescription);
            myList.addTask(taskDescription);
        }
        else if (choice == 2)
        {
            int taskNumber;
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            myList.completeTask(taskNumber - 1); // 0-based indexing
        }
        else if (choice == 3)
        {
            myList.viewTasks();
        }
        else if (choice == 4)
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid option, please try again!" << endl;
        }
    }

    return 0;
}
