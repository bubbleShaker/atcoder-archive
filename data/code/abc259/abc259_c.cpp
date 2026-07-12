#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S, T;
    cin >> S >> T;
    
    vector<pair<char, int>> cs;
    vector<pair<char, int>> ct;
    
    for(int i = 0; i < S.size();){
        int t = i;
        char tmp = S[i];
        int count = 0;
        while(S[t] == tmp){
            count++;
            t++;
        }
        cs.push_back(pair(S[i], count));
        i += count;
    }
    
    for(int i = 0; i < T.size(); i++){
        int t = i;
        char tmp = T[i];
        int count = 0;
        while(T[t] == tmp){
            count++;
            t++;
        }
        ct.push_back(pair(T[i], count));
        i += count - 1;
    }
    
    if(cs.size() != ct.size()){
        cout << "No" << endl;
        return 0;
    }
    
    for(int i = 0; i < cs.size(); i++){
        if(cs[i].first != ct[i].first){
            cout << "No" << endl;
            return 0;
        }
        if(cs[i].second == 1){
            if(ct[i].second != 1){
                cout << "No" << endl;
                return 0;
            }
        }else if(cs[i].second > ct[i].second){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}