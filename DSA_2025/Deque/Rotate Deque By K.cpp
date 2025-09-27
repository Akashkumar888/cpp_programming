
class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        // queue
        //   ↔ Rear      [ A ] [ B ] [ C ] [ D ]    Front ↔
        //   push/queue↑                            ↑queue/pop
        
        // deque 
        //   ↔ Rear     [ A ] [ B ] [ C ] [ D ]     Front ↔
        //   push_back/dequeue↑                     ↑dequeue/push_front
        while(k--){
            if(type==1){ //Right Rotation (Clockwise): If type = 1,
                dq.push_front(dq.back());
                dq.pop_back();
            }
            else{//Left Rotation (Anti-Clockwise): If type = 2,
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
};

// dq.front() → gives the element at the beginning (leftmost side).
// dq.back() → gives the element at the end (rightmost side).
// dq.push_front(x) → inserts at the front (left side).
// dq.push_back(x) → inserts at the back (right side).
// dq.pop_front() → removes from the front.
// dq.pop_back() → removes from the back.

// In deque,
// Front = left side
// Rear/Back = right side