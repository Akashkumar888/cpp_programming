
#include<iostream>
using namespace std;

class Maxheap{
public:
int arr[50];
int idx;

Maxheap(){
    idx=1; // constructor
}

int top(){
    return arr[1];
}
void push(int val){
 arr[idx]=val;
int i=idx;
idx++;
// swapping of i with parent till i==1
while(i!=1){
    // int parent=i/2;
    if(arr[i/2]<arr[i]) swap(arr[i],arr[i/2]);
    else break;
    i=i/2;
}
}
void pop(){
if(idx==0) cout<<"heap is empty()";
else idx--;
arr[1]=arr[idx];
int i=1;
while(true){
    int left=2*i;
    int right=2*i+1;
    if(left>idx-1) break;
    if(right>idx-1) {
        if(arr[i]<arr[left]){
        swap(arr[i],arr[left]);
        i=left;
        }
    break;
    }
    if(arr[left]>arr[right]){
        if(arr[i]<arr[left]){
        swap(arr[i],arr[left]);
        i=left;
        }
        else break;
    }
    else{
        if(arr[i]<arr[right]){
        swap(arr[i],arr[right]);
        i=right;
        }
        else break;
    }
}
}
int size(){
    return idx-1;
}
void display(){
    for(int i=1;i<=idx-1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
int main(){
Maxheap* pq= new Maxheap(); // constructor call
//Maxheap pq;
pq->push(10);
pq->push(20);
pq->push(11);
cout<<pq->size()<<endl;
cout<<pq->top()<<endl;
pq->display();
pq->push(30);
pq->push(40);
pq->push(12);
pq->push(4);
pq->push(7);
pq->push(2);
cout<<pq->size()<<endl;
cout<<pq->top()<<endl;
pq->display();
pq->pop();
cout<<pq->size()<<endl;
cout<<pq->top()<<endl;
pq->display();
pq->pop();
cout<<pq->size()<<endl;
cout<<pq->top()<<endl;
pq->display();

    return 0;
}