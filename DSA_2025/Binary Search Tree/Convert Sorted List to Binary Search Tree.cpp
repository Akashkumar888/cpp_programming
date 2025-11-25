
class Solution {
public:
TreeNode*solve(ListNode* head){
    if(!head)return NULL;
         // Only one node -> it becomes a leaf
        if (!head->next) 
            return new TreeNode(head->val);
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*slow_prev=NULL;
        while(fast && fast->next){ // if odd length then it find middle and id evenlength then right middle
        slow_prev=slow;
        slow=slow->next;
        fast=fast->next->next;
        }
        TreeNode*root=new TreeNode(slow->val);
        slow_prev->next=NULL;
        root->left=solve(head);
        root->right=solve(slow->next);
        return root;
}
// singly linked list where elements are sorted in ascending order,
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};