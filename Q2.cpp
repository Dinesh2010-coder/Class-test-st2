// Dinesh Khemka
// 2010990206
// Set - 1

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

vector<pair<int, int>> sortmap(unordered_map<int, int>& freqmap){
    vector<pair<int, int>> v;
    
    for(auto& p: freqmap)
        v.push_back(p);
        
    sort(begin(v), end(v), cmp);
    return v;
}

int main()
{
    // declaring map
    unordered_map<int, int> freqmap;
    // taking map as input
    cout<<"Enter size of map : "<<endl;
    int size;
    cin>>size;
    int key, value;
    cout<<"Enter elements of map : "<<endl;
    for(int i=0; i<size; i++){
        cin>>key>>value;
        freqmap[key] = value;
    }
    
    // sorting map
    vector<pair<int, int>> result = sortmap(freqmap);
    // printing map
    cout<<"Displaying Map : "<<endl;
    for(auto& x: result){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    return 0;
}