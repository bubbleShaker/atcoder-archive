#include <bits/stdc++.h>
using namespace std;

vector<int> cb(string S){
    vector<int> t1;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'B') t1.push_back(i);
    }
    return t1;
}

vector<int> cr(string S){
    vector<int> t1;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'R') t1.push_back(i);
    }
    return t1;
}

int ck(string S){
    int t1;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'K') t1 = i;
    }
    return t1;
}

bool solve(){
    string S;
    cin >> S;
    
    vector<int> t1 = cb(S);
    
    if(t1[0]%2 == t1[1]%2) return false;
    
    vector<int> t2 = cr(S);
    
    int t3 = ck(S);
    
    if(t2[0] < t3 && t2[1] > t3) return true;
    else return false;
}

int main(void){
    if(solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}