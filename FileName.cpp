#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    string dueDate;
    bool completed;
};

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter Ticket description: ";
    // Read the description including whitespaces
    getline(cin >> ws, newTask.description);
    cout << "Enter due date (YYYY-MM-DD): ";
    cin >> newTask.dueDate;
    newTask.completed = false;
    tasks.push_back(newTask);
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "Ticket:" << endl;
    cout << "----------------------------------------" << endl;
    cout << setw(10) << "Description" << setw(15) << "Due Date" << setw(12) << "Completed" << endl;
    cout << "----------------------------------------" << endl;
    for (const auto& task : tasks) {
        // Output task details
        cout << setw(10) << task.description << setw(15) << task.dueDate << setw(12) << (task.completed ? "Yes" : "No") << endl;
    }
    cout << "----------------------------------------" << endl;
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter index of Ticket to mark as completed: ";
    cin >> index;
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Ticket marked as completed." << endl;
    }
    else {
        cout << "Invalid index." << endl;
    }
}

// Function to delete a task
void deleteTask(vector<Task>& tasks) {
    int index;
    cout << "Enter index of Ticket to delete: ";
    cin >> index;
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Ticket was deleted." << endl;
    }
    else {
        cout << "Invalid index." << endl;
    }
}

// Function to save tasks to a file
void saveTasksToFile(const vector<Task>& tasks, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& task : tasks) {
            // Save task details to file
            outFile << task.description << "," << task.dueDate << "," << (task.completed ? "1" : "0") << endl;
        }
        cout << "Ticket saved to " << filename << endl;
    }
    else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

// Function to load tasks from a file
void loadTasksFromFile(vector<Task>& tasks, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        tasks.clear();
        string line;
        while (getline(inFile, line)) {
            Task task;
            size_t commaPos = line.find(',');
            // Parse task details from file
            task.description = line.substr(0, commaPos);
            line.erase(0, commaPos + 1);
            commaPos = line.find(',');
            task.dueDate = line.substr(0, commaPos);
            line.erase(0, commaPos + 1);
            task.completed = (line == "1");
            tasks.push_back(task);
        }
        cout << "Ticket loaded from " << filename << endl;
    }
    else {
        cout << "Error: Unable to open file for reading. Creating new file." << endl;
        // Attempt to create the file if it doesn't exist
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Error: Unable to create file." << endl;
        }
    }
}

int main() {
    vector<Task> tasks;
    string filename = "tasks.txt";
    loadTasksFromFile(tasks, filename);

    int choice;
    do {
        cout << "\nTask Management System" << endl;
        cout << "1. Add Ticket" << endl;
        cout << "2. View Ticket" << endl;
        cout << "3. Mark Ticket as Completed" << endl;
        cout << "4. Delete Ticket" << endl;
        cout << "5. Save Ticket" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markTaskCompleted(tasks);
            break;
        case 4:
            deleteTask(tasks);
            break;
        case 5:
            saveTasksToFile(tasks, filename);
            break;
        case 6:
            cout << "Exiting program. Saving tasks..." << endl;
            saveTasksToFile(tasks, filename);
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    return 0;
}
