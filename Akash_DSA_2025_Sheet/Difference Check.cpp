class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        // strings in 24-hour clock format "HH:MM:SS", 
        int n=arr.size();
        vector<long long>ans;
        for(int i=0;i<n;i++){
            string hr=arr[i].substr(0,2);
            string mn=arr[i].substr(3,2);
            string sec=arr[i].substr(6,2);
            ans.push_back(3600*stoi(hr)+60*stoi(mn)+stoi(sec));
        }
        sort(ans.begin(),ans.end());
        long long minTime=LLONG_MAX;
        for(int i=0;i<n-1;i++){
            minTime=min(minTime,ans[i+1]-ans[i]);
        }
        // Consider time around midnight
        minTime = min(minTime, 86400 - ans[n-1] + ans[0]);
        return (int)minTime;
    }
};
// ✅ Version 1: Using Sorting (sort method)
// Logic:
// Convert all time strings into integer values (seconds/minutes)
// Sort the list
// Check adjacent differences and wrap-around difference
// 🕒 Time Complexity:
// Parsing Strings → O(n)
// Sorting → O(n log n)
// Finding differences → O(n)
// Overall Time: O(n log n)

// 💾 Space Complexity:
// You store all converted times in a vector → O(n)
// Overall Space: O(n)



class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        // strings in 24-hour clock format "HH:MM:SS", minimum difference in seconds
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            string hr=arr[i].substr(0,2);
            string mn=arr[i].substr(3,2);
            string sec=arr[i].substr(6,2);
            ans.push_back(3600*stoi(hr)+60*stoi(mn)+stoi(sec));
        }
        sort(ans.begin(),ans.end());
        int minSeconds=INT_MAX;
        for(int i=0;i<n-1;i++){
            minSeconds=min(minSeconds,ans[i+1]-ans[i]);
        }
        // Consider time around midnight
        // ek din me 86400 seconds 
        minSeconds = min(minSeconds, 86400 - ans[n-1] + ans[0]);
        return minSeconds;
    }
};


class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        // strings in 24-hour clock format "HH:MM:SS", minimum difference in seconds
        int n=arr.size();
        int minSeconds=INT_MAX;
        vector<bool>visited(86400,false);
        for(int i=0;i<n;i++){
            string hr=arr[i].substr(0,2);
            string mn=arr[i].substr(3,2);
            string sec=arr[i].substr(6,2);
            int val=(3600*stoi(hr)+60*stoi(mn)+stoi(sec));
            if(!visited[val])visited[val]=true;
            else minSeconds=min(minSeconds,val-val);
        }
        int first=-1,second=-1;
        int firstTime=-1;
        for(int i=0;i<86400;i++){
            if(visited[i]){
                if(second==-1){
                    second=i;
                    firstTime=i;
                }
                else{
                    first=second;
                    second=i;
                }
            }
        if(first!=-1&&second!=-1)minSeconds=min(minSeconds,second-first);
        }
        // Consider time around midnight
        // ek din me 86400 seconds 
        minSeconds = min(minSeconds, 86400 - second + firstTime);
        return minSeconds;
    }
};

          class Solution {
          public:
              int findMinDifference(vector<string>& timePoints) {
                  // 24-hour clock time points in "HH:MM" format,minimum minutes difference 
                  int n=timePoints.size();
                  vector<int>ans;
                  for(int i=0;i<n;i++){
                      string hr=timePoints[i].substr(0,2);
                      string mn=timePoints[i].substr(3,2);
                      ans.push_back(60*stoi(hr)+stoi(mn));
                  }
                  sort(ans.begin(),ans.end());
                  int minMinutes=INT_MAX;
                  for(int i=0;i<n-1;i++){
                      minMinutes=min(minMinutes,ans[i+1]-ans[i]);
                  }
                  // Consider time around midnight
                  // ek din me 1440 minutes
                  minMinutes = min(minMinutes, 1440 - ans[n-1] + ans[0]);
                  return minMinutes;
              }
          };
          
          class Solution {
          public:
              int findMinDifference(vector<string>& timePoints) {
                  // 24-hour clock time points in "HH:MM" format,minimum minutes difference 
                  int n=timePoints.size();
                  int minMinutes=INT_MAX;
                  vector<bool>visited(1440,false);
                  for(int i=0;i<n;i++){
                      string hr=timePoints[i].substr(0,2);
                      string mn=timePoints[i].substr(3,2);
                      int val=(60*stoi(hr)+stoi(mn));
                      if(!visited[val])visited[val]=true;
                      else minMinutes=min(minMinutes,val-val);
                  }
                  int first=-1,second=-1;
                  int firstTime=-1;
                  for(int i=0;i<1440;i++){
                      if(visited[i]){
                          if(second==-1){
                              second=i;
                              firstTime=i;
                          }
                          else{
                              first=second;
                              second=i;
                          }
                      }
                  if(first!=-1&&second!=-1)minMinutes=min(minMinutes,second-first);
                  }
                  // Consider time around midnight
                  // ek din me 1440 minutes
                  minMinutes = min(minMinutes, 1440 - second + firstTime);
                  return minMinutes;
              }
          };

// ✅ Version 2: Using Boolean Array (Visited Array)
// Logic:
// Since total possible time values are:
// 86400 seconds
// 1440 minutes
// Use a boolean array to track presence of time points.
// Avoid sorting.
// 🕒 Time Complexity:
// Parsing and filling boolean array → O(n)
// Linear scan of fixed-size array → O(86400) or O(1440) → constant
// Overall Time: O(n) (amortized, due to fixed upper bound)

// 💾 Space Complexity:
// Visited array:
// Seconds version: vector<bool> visited(86400, false)
// Minutes version: vector<bool> visited(1440, false)
// Overall Space: O(1) (since max size is fixed)

