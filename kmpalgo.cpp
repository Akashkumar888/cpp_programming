
#include<iostream>
#include<vector>
using namespace std;
int main()
{
string s="abcdabcd";
vector<int>LPS(s.size());
	    int pre=0,suf=1;
	    while(suf<s.size()){
	        if(s[pre]==s[suf]){
	            LPS[suf]=pre+1;
	            pre++,suf++;
	        }
	        else{
	            if(pre==0){
	                LPS[suf]=0;
	                suf++;
	            }
	            else{
	                pre=LPS[pre-1];
	            }
	        }
	    }
	    cout<< LPS[s.size()-1];
return 0;
}