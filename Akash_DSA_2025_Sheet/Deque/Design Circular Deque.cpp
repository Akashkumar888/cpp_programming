
class MyCircularDeque {
public:
//list<int>ans; dpubly linked list
int countsize;
list<int>ans;
int l;
    MyCircularDeque(int k) {
        countsize=0;
        l=k;
    }
    
    bool insertFront(int value) {
        if(isFull())return false;
        ans.push_front(value);
        countsize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        ans.push_back(value);
        countsize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        ans.pop_front();
        countsize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        ans.pop_back();
        countsize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return ans.front();
    }
    
    int getRear() {
        if(isEmpty())return -1;
        return ans.back();
    }
    
    bool isEmpty() {
        return (countsize==0);
    }
    
    bool isFull() {
        return countsize==l;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */