#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Task {
    int id;
    string title;
    int priority;      // 1 = most urgent
    bool done = false;
};
struct ByPriority {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority == b.priority) return a.id > b.id;
        return a.priority > b.priority;
    }
    void saveTasks(const vector<Task>& tasks) {
    ofstream out("tasks.txt");
    for (const Task& t : tasks)
        out << t.id << " " << t.priority << " " << t.done << "\n"
            << t.title << "\n";
}

int loadTasks(vector<Task>& tasks) {
    ifstream in("tasks.txt");
    int maxId = 0;
    Task t;
    while (in >> t.id >> t.priority >> t.done) {
        in.ignore();
        getline(in, t.title);
        tasks.push_back(t);
        if (t.id > maxId) maxId = t.id;
    }
    return maxId;
}
};
void saveTasks(const vector<Task>& tasks) {
    ofstream out("tasks.txt");
    for (const Task& t : tasks)
        out << t.id << " " << t.priority << " " << t.done << "\n"
            << t.title << "\n";
}

int loadTasks(vector<Task>& tasks) {
    ifstream in("tasks.txt");
    int maxId = 0;
    Task t;
    while (in >> t.id >> t.priority >> t.done) {
        in.ignore();
        getline(in, t.title);
        tasks.push_back(t);
        if (t.id > maxId) maxId = t.id;
    }
    return maxId;
}
int main() {
    vector<Task> tasks;
    int nextId = loadTasks(tasks) + 1;
    int choice;

    do {
        cout << "\n1. Add task\n2. List tasks\n3. Complete task\n4. Show by urgency\n0. Exit\n> ";
        if (!(cin >> choice)) {
    cin.clear();
    cin.ignore(10000, '\n');
    choice = -1;
    cout << "Please enter a number.\n";
    continue;
}

        if (choice == 1) {
            Task t;
            t.id = nextId++;
            cin.ignore();
            cout << "Title: ";
            getline(cin, t.title);
            cout << "Priority (1-5): ";
            while (!(cin >> t.priority) || t.priority < 1 || t.priority > 5) {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Enter a number from 1 to 5: ";
}
            tasks.push_back(t);
        } else if (choice == 2) {
            for (const Task& t : tasks) {
                cout << "[" << (t.done ? "x" : " ") << "] "
                     << t.id << ". " << t.title
                     << " (P" << t.priority << ")\n";
            }
        } else if (choice == 3) {
            int id;
            cout << "Task ID to complete: ";
            cin >> id;
            bool found = false;
            for (Task& t : tasks) {
                if (t.id == id) {
                    t.done = true;
                    found = true;
                    cout << "Nice work! Task completed.\n";
                    break;
                }
            }
            if (!found) cout << "No task with that ID.\n";
        } else if (choice == 4) {   
    priority_queue<Task, vector<Task>, ByPriority> pq;
    for (const Task& t : tasks)
        if (!t.done) pq.push(t);

    if (pq.empty()) cout << "Nothing pending. Great job!\n";
    while (!pq.empty()) {
        Task t = pq.top();
        pq.pop();
        cout << "P" << t.priority << " - " << t.title << "\n";
    }
}
        saveTasks(tasks);
    } while (choice != 0);
}
