
// 🧠 What is stringstream in C++?
// 👉 stringstream (from <sstream>) is used to:

// Break a string into words (tokenization)
// Convert between string ↔ numbers
// Process input like cin, but from a string
// Think of it like:

// 🔹 cin reads from keyboard
// 🔹 stringstream reads from a string

// ✅ Basic Syntax
// #include<bits/stdc++.h>

#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string str = "Hello World";
    stringstream ss(str);

    string word;
    while (ss >> word) {
        cout << word << endl;
    }

    return 0;
}

// 👉 Output:
// Hello
// World

#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string str = "akash     kumar";  // multiple spaces
    stringstream ss(str);

    string temp;
    while (getline(ss, temp, ' ')) {
        if (temp != "") {  // ignore empty tokens
            cout << temp << endl;
        }
    }

    return 0;
}


// reverse words using stringstream 
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str = "akash     kumar   singh   rajput";
    stringstream ss(str);

    vector<string> words;
    string temp;

    // Extract words (automatically skips multiple spaces)
    while (ss >> temp) {
        words.push_back(temp);
    }

    // Reverse words
    reverse(words.begin(), words.end());

    // Print with single space
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
        if (i != words.size() - 1) cout << " ";
    }

    return 0;
}


// by using getline 


#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str = "akash     kumar   singh   rajput"; // multiple words + spaces
    stringstream ss(str);

    vector<string> words;
    string temp;

    // Step 1 & 2: Extract words, ignore empty ones
    while (getline(ss, temp, ' ')) {
        if (temp != "") {
            words.push_back(temp);
        }
    }

    // Step 3: Reverse words
    reverse(words.begin(), words.end());

    // Step 4: Print with single space
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
        if (i != words.size() - 1) cout << " ";
    }

    return 0;
}


// write code 

// 🔥 1️⃣ Count Words in a String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "akash     kumar   singh";

    stringstream ss(str);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }

    cout << "Word count: " << count;

    return 0;
}

// 🔥 2️⃣ Reverse Sentence (Your Main Problem)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "akash     kumar   singh";

    stringstream ss(str);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    for (int i = 0; i < words.size(); i++) {
        if (i > 0) cout << " ";
        cout << words[i];
    }

    return 0;
}


// 🔥 3️⃣ String to Integer
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "12345";

    stringstream ss(s);
    int x;

    ss >> x;

    cout << "Integer value: " << x;

    return 0;
}


// 🔥 4️⃣ Integer to String
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 6789;

    stringstream ss;
    ss << x;

    string s = ss.str();

    cout << "String value: " << s;

    return 0;
}


// 🔥 5️⃣ Sum of Numbers in a String
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "10 20   30  40";

    stringstream ss(str);
    int num, sum = 0;

    while (ss >> num) {
        sum += num;
    }

    cout << "Sum: " << sum;

    return 0;
}



// 🔥 6️⃣ Remove Extra Spaces (VERY IMPORTANT)
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "   akash     kumar   singh   ";

    stringstream ss(str);
    string word, result = "";

    while (ss >> word) {
        if (!result.empty()) result += " ";
        result += word;
    }

    cout << "Clean string: " << result;

    return 0;
}


// 🔥 7️⃣ Find Longest Word
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "akash kumar singh rajput";

    stringstream ss(str);
    string word, longest = "";

    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    cout << "Longest word: " << longest;

    return 0;
}


// 🔥 8️⃣ Count Frequency of Words
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "akash kumar akash singh kumar akash";

    stringstream ss(str);
    map<string, int> freq;
    string word;

    while (ss >> word) {
        freq[word]++;
    }

    for (auto &p : freq) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}



// 🔥 9️⃣ Extract Only Numbers from Mixed String
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "10 akash 20 kumar 30";

    stringstream ss(str);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            cout << token << " ";
        }
    }

    return 0;
}



// 🔥 🔟 Check if String Contains Only Numbers
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "12345";

    stringstream ss(str);
    int num;
    string temp;

    if (ss >> num && !(ss >> temp)) {
        cout << "Valid number";
    } else {
        cout << "Not a valid number";
    }

    return 0;
}



// 🧠 1️⃣ What is stringstream? (Short Answer)
// 👉 Say this first:
// “stringstream is a class in C++ used to treat a string like a stream, similar to cin, so we can extract data from a string easily.”

// 🔄 2️⃣ How stringstream Works Internally
// 👉 Think like this:

// cin → reads from keyboard
// stringstream → reads from string
// 🔹 Step-by-step working
// string str = "akash kumar";
// stringstream ss(str);

// 👉 Internally:

// Buffer inside ss:
// [ a k a s h   k u m a r ]
// 🔁 Extraction using >>
// string word;
// ss >> word;

// 👉 What happens:
// Skips leading spaces
// Reads characters until space
// Stores into word
// 🔁 Iteration
// Step	Extracted
// 1	akash
// 2	kumar

// 🔥 3️⃣ Important Behavior (VERY IMPORTANT)
// ✅ Automatically skips spaces
// string str = "akash     kumar";

// 👉 Still gives:
// akash
// kumar

// ✔ No empty strings
// ✔ Clean parsing

// ⚠️ 4️⃣ >> vs getline
// Feature	ss >> word	getline(ss, temp, ' ')
// Skips multiple spaces	✅	❌
// Returns empty tokens	❌	✅
// Cleaner for words	✅	❌
// 🧪 5️⃣ Example Explanation (Use This in Interview)

// From your code :
stringstream ss(str);
while (ss >> word) {
    words.push_back(word);
}

// 👉 Explain like this:
// “Here, stringstream creates a stream from the string. Then >> operator extracts words one by one, automatically skipping spaces. Each extracted word is stored and processed.”

// 🔥 6️⃣ Internal Flow (Best Explanation)
// Say this:
// “Internally, stringstream maintains a buffer of the string and a read pointer. Each time we use >>, it moves the pointer forward, extracts the next token based on delimiters like space, and skips unnecessary whitespace.”

// 🚀 7️⃣ Final Interview Answer (BEST VERSION)
// If interviewer asks:
// 👉 “How does stringstream work?”
// Say:
// “stringstream works like cin, but instead of reading from the keyboard, it reads from a string buffer. Internally, it maintains a stream and a pointer. When we use the extraction operator (>>), it skips whitespace and reads data token by token. This makes it very useful for parsing strings, converting data types, and handling formatted input.”

// 🔥 8️⃣ One-Line Killer Statement
// 👉 Say this confidently:
// “stringstream converts a string into a stream so we can use input operations like >> on it.”

// 🎯 9️⃣ When to Use (Interview Bonus)
// Say:

// Parsing sentences
// Removing extra spaces
// Converting string ↔ numbers
// Tokenizing input