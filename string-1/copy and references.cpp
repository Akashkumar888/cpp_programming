
#include<bits/stdc++.h>

using namespace std;
int main()
{
// 🔹 In C++
// Things are different.
// 1️⃣ Without & (Copy happens)


vector<string> names = {"Ram","Harish","Karan","Monty"};

for (string name : names) {
    cout << name<<" ";
}
cout<<endl;

for(string name:names){
  name="Updated"; // name is a copy of each string. 
}


for (string name : names) {
    cout << name<<" ";
}
cout<<endl;

// Here:
// name is a copy of each string.
// Every iteration creates a new string object.
// Slower for large objects.
// 2️⃣ With & (No Copy)

vector<string>Employees={"Akash","Surya","Ankit","Aditya"};

for (string &Employee : Employees) {
    cout << Employee<<" ";
}

cout<<endl;

// Here:
// name is a reference to original element
// No copying
// Faster
// Can modify original element
// Example:

for (string &Employee : Employees) {
     Employee="Updated";
}

cout<<endl;

for (string &Employee : Employees) {
    cout << Employee<<" ";
}

// Now original vector changes.


return 0;
}
