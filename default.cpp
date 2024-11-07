
#include <iostream>
#include <string>

using namespace std;

// Equivalent to: sayname(fname="ankit", lname)
void sayname(string fname = "ankit", string lname = "") {
    cout << "My name is: " << fname << " " << lname << endl;
}

// Equivalent to: sayname(fname="ankit", lname="surya")
void sayname2(string fname = "ankit", string lname = "surya") {
    cout << "My name is: " << fname << " " << lname << endl;
}

// Equivalent to: sayname(fname, lname="surya")
void sayname3(string fname, string lname = "surya") {
    cout << "My name is: " << fname << " " << lname << endl;
}

// Equivalent to: sayname(fname, lname)
void sayname4(string fname, string lname) {
    cout << "My name is: " << fname << " " << lname << endl;
}

int main() {
    sayname("akash");            // Outputs: "akash"
    sayname2("akash");           // Outputs: "akash surya"
    sayname3("akash");           // Outputs: "akash surya"
    sayname4("akash", "kumar");  // Outputs: "akash kumar"
    return 0;
}
