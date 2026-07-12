#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, N;
    
    cin >> N;
    
    vector<pair<int, int>> p(N);
    
    for(i = 0; i < N; i++){
        cin >> p.at(i).first >> p.at(i).second;
    }
    
    for(auto &a : p){
        int t;
        t = a.first;
        a.first = a.second;
        a.second = t;
    }
    
    sort(p.begin(), p.end());
    
    for(auto &a : p){
        int t;
        t = a.first;
        a.first = a.second;
        a.second = t;
        cout << a.first << " " << a.second << endl;
    }
}