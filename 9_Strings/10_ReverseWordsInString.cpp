#include<bits/stdc++.h>
using namespace std;

void reverse(char str[], int low, int high){ // revers a word from index low-high
    while(low <= high){
        swap(str[low],str[high]);
        low++;
        high--;
    }
}

void reverseWords(char str[], int n){
    int start=0;
    for(int end=0;end<n;end++){
        if(str[end]==' '){
            reverse(str,start,end-1); // to reverse each word
            start = end+1;
        } // start = 11, emocleW ot India
    }
    reverse(str, start,n-1); // to reverse last word of string
    // emocleW ot aidnI
    reverse(str,0,n-1); // reverse whole string
}                       // India to Welcome

int main(){
    char str[] = "Welcome to India";
    int n=sizeof(str); // it will be 16+1 due to '/0' at end
    reverseWords(str,n-1);
    for(int i=0;i<n-1;i++){
        cout << str[i] << " ";
    }
    return 0;
}