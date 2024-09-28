// #include<iostream>
// using namespace std;
// int main(){
//     char str[100];
//     int vowels=0;

//     // getline(cin,s);


//     cin.get(str,100);


//     for(int i=0;str[i]!='\0';i++){
//       if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' || str[i]=='o' || str[i]=='u' ||str[i]=='A' ||str[i]=='E' ||str[i]='I' || str[i]=='O' || str[i]=='U' ){
//         vowels++;
//       }
//     }
//     cout<<vowels;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    char str[100];
    int count = 0;

    cout << "Enter a string to test :" ;
    cin.get(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
    }

    cout << "Total number of vowels found :  " << count << endl;
}