#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> a(M);
    vector<set<int>> s(M);
    for(int i = 0; i < M; i++){
        int c;
        cin >> c;
        for(int j = 0; j < c; j++){
            int t;
            cin >> t;
            a[i].push_back(t);
            s[i].insert(t);
        }
    }
    
    int c = 0;
    
    for(int bit = 0; bit < (1 << M); bit++){
        vector<int> tmp;
        
        for(int i = 0; i < M; i++){
            if(bit & (1<<i)){
                tmp.push_back(i);
            }
        }
        
        bool f;
        
        for(int i = 1; i <= N; i++){
            f = false;
            for(int j = 0; j < tmp.size(); j++){
                if(s[tmp[j]].count(i)){
                    f = true;
                    break;
                }
            }
            if(!f) break;
        }
        
        if(!f) continue;
        else c++;
    }
    
    cout << c << endl;
    return 0;
    
}