
#include <bits/stdc++.h>
using namespace std;

struct Patient {
    int id;
    int priority;
    int time;
    // Constructor
    Patient(int id, int priority, int time) : id(id), priority(priority), time(time) {}
};

// Placeholder function where user will implement the logic
vector<int> determineVisitOrder(vector<Patient>& patients) {
    // User should implement logic here
    // This function should return a vector of integers representing the order of IDs
    
    // comparator or lambda functions
    auto cmp=[&](const Patient &a,const Patient &b){
         // 1. Higher priority first
        if (a.priority != b.priority) return a.priority > b.priority;

        // 2. Lower treatment time first
        if (a.time != b.time) return a.time < b.time;

        // 3. Lower ID first
        return a.id < b.id;
    };

    sort(patients.begin(), patients.end(),cmp);

    vector<int> result;
    for (auto &p : patients) {
        result.push_back(p.id);
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<Patient> patients;
    for (int i = 0; i < N; ++i) {
        int id, priority, time;
        cin >> id >> priority >> time;
        patients.emplace_back(id, priority, time);
    }

    // Call user logic function
    vector<int> visitOrder = determineVisitOrder(patients);

    // Output the result
    for (int id : visitOrder) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}


// 💡 Is Lambda Needed with [&]?
// You wrote:
// auto cmp = [&](const Patient &a,const Patient &b)

// You are not using any external variables inside the lambda.
// So you can even write:
// auto cmp = [](const Patient &a,const Patient &b)
// Both are correct.
// But [] is cleaner here.

// 🧠 Interview Answer
// If interviewer asks:
// “Why did you use comparator?”
// You can say:
// "Because default sort sorts in ascending order, but here we need multiple custom conditions: priority descending, time ascending, and ID ascending. So I used a custom comparator."
