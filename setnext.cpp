// C++ program to access
// element by index in set.
#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> s;

	// Inserting values in set
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	
	// Index(considering 0 as starting index)
	int n=3;
	
	// Initializing iterator and
	// iterating n times 
	// using next() function
	auto it = next(s.begin(), n);
	
	// Printing the element at index n
	cout<<*it;

	return 0;
}
