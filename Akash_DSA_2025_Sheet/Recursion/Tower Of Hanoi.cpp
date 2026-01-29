
class Solution {
  public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
void towerOfHanoi(int n,int src,int helper,int dest){
if(n==1){
    cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<endl;
    return;
}

towerOfHanoi(n-1,src,dest,helper);
cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<endl;
towerOfHanoi(n-1,helper,src,dest);

}
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        towerOfHanoi(n,from,aux,to);
        return pow(2,n)-1;
        
    }
};

// “Badi disk ko move karne ke liye, pehle uske upar ki sab chhoti disks hatao.”
// Iska matlab har step me 3 kaam hote hain:
// Top (n-1) disks ko src → helper bhejo (using dest)
// Nth (badi) disk ko src → dest bhejo
// Wapas (n-1) disks ko helper → dest bhejo (using src)

// Isko yaad rakhne ka one-line trick:
// “(n-1) hatao, n ko bhejo, (n-1) wapas lao.”
// Ya rhyme style:
// Chhote hatao,
// Bada bhejo,
// Chhote wapas lao.

// toh function:
// long long toh(int n, int from, int to, int aux) {
//     towerOfHanoi(n, from, aux, to);
//     return (1LL << n) - 1;   // better than pow(2,n)
// }

// Bas itna yaad rakho—
// हर बार n ko move karne se pehle (n-1) ko hataana zaroori hai. यही Tower of Hanoi ka core logic hai.