#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    cin >> S;
    
    map<string, int> node;
    queue<string> que;
    
    que.push(S);
    node[S] = 0;
    
    while(!que.empty()){
        string t = que.front();
        que.pop();
        
        for(int i = 0; i + 1 < t.size(); i++){
            string t2 = t;
            swap(t2[i], t2[i+1]);
            if(node.count(t2)) continue;
            que.push(t2);
            node[t2] = node[t] + 1;
        }
    }
    
    cout << node["atcoder"] << endl;
    
    return 0;
}
