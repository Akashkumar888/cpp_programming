
class Solution {
  public:
  bool isPrime(int n){
      if(n<=1)return false;
      for(int i=2;i*i<=n;i++){
          if(n%i==0)return false;
      }
      return true;
  }
  int nearest(int n){
        int prev=n-1;
        int next=n+1;
      while(true){
          if(prev>=2 && isPrime(prev))return prev;
          if(isPrime(next))return next;
          prev--;
          next++;
      }
  }
    Node *primeList(Node *head) {
        // code here
        Node*temp=head;
        while(temp){
            if(!isPrime(temp->val)){
            temp->val=nearest(temp->val);
            }
            temp=temp->next;
        }
        return head;
    }
  };
  