#include<bits/stdc++.h>
using namespace std;
struct KStacks{
     int *arr,*top,*next;
     int k,freeTop,cap;
     KStacks(int k1,int n){
         k=k1;
         cap=n;
         arr = new int[cap]; // to store k stacks
         top = new int[k];   // to store top for k stacks
         next = new int[cap];// to keep a stack linked
         // 1 2 3 4......cap-1 -1
         for(int i=0;i<k;i++)
            top[i] = -1;
        freeTop = 0;
        for(int i=0;i<cap-1;i++)
            next[i] = i+1;
        next[cap-1] = -1;
     }
     void push(int x,int sn){
         int i = freeTop;
         freeTop = next[i];
         next[i] = top[sn]; // to keep link with prev stack element
         top[sn] = i; // update top
         arr[i] = x;
     }
     int pop(int sn){
         int i=top[sn];
         top[sn] = next[i];// make top = prev ele. index
         next[i] = freeTop;
         freeTop = i;
         return arr[i];
     }
 };

int main(){
    KStacks ks(3,6);
    ks.push(100,0);
    ks.push(200,0);
    ks.push(300,0);
    ks.push(400,1);
    ks.push(500,0);
    cout << ks.pop(1) << endl;
    cout << ks.pop(0) << endl;
    return 0;
}