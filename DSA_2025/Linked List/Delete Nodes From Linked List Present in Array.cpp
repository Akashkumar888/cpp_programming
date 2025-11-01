
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
bool binarySearch(int n,vector<int>&nums,int tr){
    int l=0,r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==tr)return true;
        else if(nums[mid]<tr)l=mid+1;
        else if(nums[mid]>tr)r=mid-1;
    }
    return false;
}
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       ListNode*dummy=new ListNode(-1);
       ListNode*prev=dummy;
       ListNode*temp=head;
       while(temp){
       if(!binarySearch(n,nums,temp->val)){ // means element not found 
        prev->next=temp;
        prev=prev->next;
       }
       temp=temp->next;
       }
       prev->next=NULL;
       return dummy->next;
    }
};