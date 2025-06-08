#include <bits/stdc++.h> 
string convertString(string str) 
{	
 bool newWord = true;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            newWord = true;
        } else if (newWord && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // convert to uppercase
            newWord = false;
        } else {
            newWord = false;
        }
    }
    return str;
}



string convertString(string str) 
{
	// WRITE YOUR CODE HERE
    stringstream ss(str);
    string temp,ans;
    while(getline(ss,temp,' ')){
    string s=temp;
    if(s[0]>='a'&&s[0]<='z')s[0]=s[0]-32;
    ans+=s;
    ans+=' ';
    }
    return ans;
}



string convertString(string str) 
{	
 bool newWord = true;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            newWord = true;
        } else if (newWord && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // convert to uppercase
            newWord = false;
        } else {
            newWord = false;
        }
    }
    return str;
}

