#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Graph;
vector<int> c(1000000);
vector<int> c1(1000000);
vector<int> a1;

void dfs(int n, Graph& g){
    c[n]++;
    if(c[n] == 2) return;
    for(auto t : g[n]){
        dfs(t, g);
    }
}

void calc(int s, Graph& g){
    c1[s]++;
    if(c1[s] == 2) return;
    else{
        a1.push_back(s);
    }
    for(auto t : g[s]){
        calc(t, g);
    }
}

int main(void){
    int N;
    cin >> N;
    Graph g(N+1);
    for(int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        g[i].push_back(tmp);
    }
    
    dfs(1, g);
    for(int i = 1; i <= N; i++){
        int ma = 0;
        for(int j = 1; j <= N; j++){
            if(c[j] == 2) ma = 2;
        }
        if(ma != 2){
            for(int k = 1; k <= N; k++){
                if(c[k] == 0){
                    dfs(k, g);
                }
            }
        }else break;
    }
    int s;
    for(int i = 1; i <= N; i++){
        if(c[i] == 2) s = i;
    }
    
    vector<int> ans;
    
    calc(s, g);
    
    int e = a1.size();
    
    cout << e << endl;
    
    for(int i = 0; i < a1.size(); i++) cout << a1[i] << " \n"[i+1 == a1.size()];
    
    return 0;
}