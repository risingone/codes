#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {2, 5, 2, 1, 5};
    // it is ordered set with average time complexity for operations O(log n)
    // consist of unique elements
    //in an specific sorted order
    cout << "Sets: " << endl;
    set<int> st;
    int n=5;//5
    for(int i=0;i<n;i++){
        // int x;
        // cin >> x;      //{2,5,2,1,5}
        // st.insert(x);
        st.insert(arr[i]); // O(logn)
    }

    cout << st.size() << endl; 
    // st -> {1,2,5}
    for(auto it=st.begin();it!=st.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    
    // erase functionality
    st.erase(st.begin()); // st.erase(iterator)  // st-> {2, 5}
    st.erase(5);  // st.erase(key) // delete 5
    // st.erase(st.begin(),st.end()); //st.(iterator 1, iterator 2) to clear elements (] 
    st.emplace(3); // slightly faster than insert
    st.emplace(7); // while functionality is same
    st.emplace(0);
    st.erase(st.find(2)); // st.find(key) -> return an iterator pointing to key
    for(auto it: st){
        cout << it << " ";
    }
    cout << endl;

    // unordered set
    unordered_set<int> ust;
    ust.insert(2);
    ust.insert(3);
    ust.insert(1);

    // average time complexity is O(1)
    // tle -> switch to set
    // but the worst case is linear in nature, O(set size)

    // multiset
    cout << "Multiset: " << endl;
    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);  // ms.emplace(3)
    // ms -> {1,1,2,2,3}
     ms.emplace(5);
    ms.emplace(6);
    ms.emplace(7);
    ms.emplace(9);

    auto it = ms.find(2); // returns an iterator pointing to the first occurence of element 
    // ms.erase(it); // delete first occurence of 2 
    ms.erase(2); // will erase all instances of 2
    ms.erase(ms.find(3),ms.find(6)); // (]

    for(auto it:ms){
        cout << it << " ";
    }
    cout << endl;

    cout << "Maps: " << endl;
    // Key     ->     Value
    // raj     ->     27
    // hima    ->     31
    // sandeep ->     67
    // tank    ->     89
    map<string, int> mpp;
    mpp["raj"] = 27;
    mpp["hima"] = 31;
    mpp["sandeep"] = 67;
    mpp["tank"] = 89;
    // mpp.emplace("raj",45); // it will overwrite previous value // not working

    for(auto it= mpp.begin(); it != mpp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    cout << mpp.count("raj") << endl; // always returns 1 as it stores only 1 instance of raj
    mpp.erase("raj"); // mpp.erase(key)
    mpp.erase(mpp.begin());
    mpp.clear();
    mpp.erase(mpp.begin(),mpp.find("tank"));
    if(mpp.empty()){
        cout << "Yes it is empty" << endl;
    }

    pair<int,int> pr;
    pr.first = 1;
    pr.second = 10;

    // printing map
    for(auto it: mpp){
        cout << it.first << " " << it.second << endl;
    }

    //does not store in any order
    // unordered_map<int,int> mpp;
    //O(1) in almost all cases
    // O(n) in the worst cases, where n is the container size

    // Pair class
    cout << "Pairs: " <<endl;
    pair<int,int> pr1 = {1,2};
    pair< pair<int,int>, int> pr2 = {{1,2}, 2};
    cout << pr2.first.second << endl;
    return 0;
}