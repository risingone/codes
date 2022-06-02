#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    // int tour(petrolPump p[],int n)
    // {
    //    //Your code here
    //    queue<int> q;
    //    int tot=0;
    //    for(int i=0;i<n;i++){
    //        int diff=p[i].petrol-p[i].distance;
    //        tot += diff;
    //        if(diff>=0) q.push(i);
    //    }
    //    if(tot<0) return -1;
       
    //   while(!q.empty()){
    //       int i=q.front();
    //       int j=(i+1)%n,fuel=p[i].petrol-p[i].distance;
    //       while(fuel>=0){
    //           if(j==i) return i;
    //           fuel += (p[j].petrol-p[j].distance);
    //           j=(j+1)%n;
    //       }
    //       q.pop();
    //   }
    //    return -1;
    // }
    
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int curr=0,prev=0,start=0;
       for(int i=0;i<n;i++){
           curr += (p[i].petrol - p[i].distance);
           if(curr<0){
               start=i+1;
               prev += curr;
               curr=0;
           }
       }
       return ((prev+curr)>=0)?start:-1;
    }
};

int main(){
    Solution s;
    int n=4;
    petrolPump p[n];
    int Petrol[4]={4,6,7,4};
    int Distance[4]={6,5,3,5};
    for(int i=0;i<n;i++){
        p[i].petrol = Petrol[i];
        p[i].distance = Distance[i];
    }
    cout << s.tour(p,n) << endl;
    return 0;
}