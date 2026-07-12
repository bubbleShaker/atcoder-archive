#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, M;
    cin >> N >> M;
    
    vector<int> p(M);
    
    for(int i = 0; i < N; i++){
        p[i] = 1;
    }
    
    sort(p.begin(), p.end());
    
    set<vector<int>> s_v;
    
    do{
        vector<int> t;
        for(int i = 0; i < M; i++){
            if(p[i]) t.push_back(i+1);
        }
        s_v.insert(t);
    }while(next_permutation(p.begin(), p.end()));
    
    for(auto t : s_v){
        for(int i = 0; i < t.size(); i++){
            cout << t[i] << " \n"[i + 1 == t.size()];
        }
    }
    
    return 0;
}
