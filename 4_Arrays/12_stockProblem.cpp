/*To get maximum profit by buying stocks at less value and selling at high value*/
#include<bits/stdc++.h>
using namespace std;
//M-1 using recursion
int maxProfit(int price[],int start,int end){
    if(end<=start) return 0; //for only 1 element
    int profit=0;
    for(int i=start;i<end;i++){ //take elements fom 0 to n-2 index
        for(int j=i+1;j<=end;j++){ // take elements ahead
            if(price[j]>price[i]){ // and compare
            /*for each case take max profit from both sides*/
                int curr_profit = price[j] - price[i] + maxProfit(price,start,i-1) + maxProfit(price,j+1,end);
                profit = max(profit,curr_profit);//update profit if curr_profit is greater
            }
        }
    }
    return profit;
}
//M-2 O(n)
int maxProfit2(int price[],int n){
    int profit=0;
    for(int i=1;i<n;i++){
        if(price[i]>price[i-1]){
            profit += (price[i]-price[i-1]);
        }
    }
    return profit;
}
int main(){
    int A[]={1,5,3,8,12};
    cout << maxProfit(A,0,4) << endl; //put starting & ending index of array
    cout << maxProfit2(A,5) << endl;
    return 0;
}