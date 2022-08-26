// Dinesh Khemka
// 2010990206
// Set - 1

#include <bits/stdc++.h>
using namespace std;

// taking mean
long mean(vector<long> grades){
    return accumulate(begin(grades), end(grades), (long)0)/grades.size();
}

// taking median
long median(vector<long> grades, int size){
    sort(begin(grades), end(grades));
    
    if(size % 2 != 0){
        return grades[size/2];
    }
    
    int a = size/2;
    int b = a + 1;
    
    return (grades[a] + grades[b])/2; 
}

// taking mode
pair<vector<string>, int> mode(vector<string> names, vector<long> grades){
    unordered_map<int, int> freq;
    
    for(int i=0; i<grades.size(); i++)
        freq[grades[i]]++;
    
    int key, val = 0;
    for(auto& p: freq){
        if(p.second > val)
            key = p.first;
    }
    
    pair<vector<string>, int> ans;
    vector<string> studentsWithMode;
    for(int i=0; i<grades.size(); i++){
        if(grades[i] == freq[key])
            studentsWithMode.push_back(names[i]);
    }
    
    return ans;
}

int main()
{
    // declaring both the vectors
    vector<string> names;
    vector<long> grades;
    
    int size;
    cin>>size;
    
    string name;
    int grade;
    
    // taking vectors as input
    for(int i=0; i<size; i++){
        cin>>name>>grade;
        names.push_back(name);
        grades.push_back(grade);
    }
    
    // displaying mean
    cout<<"mean: "<<mean(grades)<<endl;

    // displaying median
    cout<<"median: "<<median(grades, size)<<endl;
    
    // displaying mode
    pair<vector<string>, int> x = mode(names, grades);
    cout<<"mode: "<<x.second<<endl<<"students with the mode ";
    for(int i=0; x.first.size(); i++){
        cout<<x.first[i]<<" ";
    }
        
    return 0;
}