
#include <iostream>
#include <string>

using namespace std;

int main() {
    // String to int conversion
    string str = "42";
    int intValue = stoi(str);  // Use stoi() function
    cout << "String to int: " << intValue << endl;

    // Int to string conversion
    int intVal = 42;
    string strVal = to_string(intVal);  // Use to_string() function
    cout << "Int to string: " << strVal << endl;

    // Char to string conversion
    char character = 'A';
    string charToStr(1, character);  // Create a string from one char
    cout << "Char to string: " << charToStr << endl;

    // String to char conversion
    string str2 = "B";
    char strToChar = str2[0];  // Access first character
    cout << "String to char: " << strToChar << endl;

    // Char to int conversion
    char charVal = '5';
    int charToInt = charVal - '0';  // Subtract ASCII value of '0' to get the number
    cout << "Char to int: " << charToInt << endl;

    // Int to char conversion
    int num = 5;
    char intToChar = num + '0';  // Add ASCII value of '0' to get the char
    cout << "Int to char: " << intToChar << endl;

    // Int to float conversion
    int intNum = 42;
    float floatNum = static_cast<float>(intNum);  // Use static_cast for type casting
    cout << "Int to float: " << floatNum << endl;

    // Float to int conversion
    float floatVal = 42.8;
    int floatToInt = static_cast<int>(floatVal);  // Use static_cast for type casting
    cout << "Float to int: " << floatToInt << endl;

    return 0;
}

// Converts a string to an integer using stoi() function.
// Converts an integer to a string using to_string() function.
// Converts a char to a string using a constructor.
// Converts a string to a char by accessing the first character.
// Converts a char to an integer by subtracting ASCII value of '0'.
// Converts an integer to a char by adding ASCII value of '0'.
// Converts an integer to a float using static_cast<float>.
// Converts a float to an integer using static_cast<int>.
