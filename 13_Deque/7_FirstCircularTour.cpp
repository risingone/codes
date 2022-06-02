#include<bits/stdc++.h>
using namespace std;

// M-1: Naive O(n^2)
int firstPetrolPump(int petrol[],int dist[],int n){
    for(int start=0;start<n;start++){
        int curr_petrol = 0;
        int end = start;
        while(true){
            curr_petrol += (petrol[end]-dist[end]);
            if(curr_petrol<0) break;
            end = (end+1)%n;
            if(end==start) return start+1;
        }
    }
    return -1;
}

// M-2: Better Solution O(n)
int firstPetrolPump2(int petrol[],int dist[],int n){
    deque<int> dq;
    int curr_petrol=0;
    int i=0;
    while(true){
        while(!dq.empty() && curr_petrol<0){
            int ind=dq.front();
            dq.pop_front();
            // if no such point exist
            if(ind==n-1) return -1;
            curr_petrol -= (petrol[ind]-dist[ind]);
        }
        curr_petrol += (petrol[i]-dist[i]);
        dq.push_back(i);
        if(dq.size()==n && curr_petrol>=0) return dq.front()+1;
        i=(i+1)%n;
    }
    return -1;
}

// M-3: Best Solution O(n)
int firstPetrolPump3(int petrol[],int dist[],int n){
    int start=0,curr_pet=0,prev_pet=0;
    for(int i=0;i<n;i++){
        curr_pet += (petrol[i]-dist[i]);
        if(curr_pet<0){
            prev_pet += curr_pet;
            curr_pet=0;
            start=i+1;
        }
    }
    return (curr_pet+prev_pet)>=0?start+1:-1;
}

int main(){
    int n=4;
    int petrol[] ={50,10,60,100};
    int dist[] = {30,20,100,10};
    // it will return position not index
    cout << firstPetrolPump(petrol,dist,n) << endl;
    cout << firstPetrolPump2(petrol,dist,n) << endl;
    cout << firstPetrolPump3(petrol,dist,n) << endl;
    return 0;
}