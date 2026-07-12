#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> k(m);
    vector<vector<int>> av(m);
    vector<stack<int>> stk(m);
    for(int i=0;i<m;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            int a;
            cin>>a;
            av[i].push_back(a);
        }
        reverse(av[i].begin(),av[i].end());
        for(int j=0;j<k[i];j++){
            stk[i].push(av[i][j]);
        }
    }
    map<int,int> mp;
    map<int,set<int>> imp;//2つあるのが同じstackならただちにNo
    set<int> st;
    for(int i=0;i<m;i++){
        mp[stk[i].top()]++;
        imp[stk[i].top()].insert(i);
        if(mp[stk[i].top()]==2){
            st.insert(stk[i].top());
        }
    }
    int s=0;
    while(st.size()!=0){
        vector<int> px;
        vector<int> nx;
        for(auto x:st){
            // cout<<x<<endl;
            if(imp[x].size()!=2){
                cout<<"No"<<endl;
                return 0;
            }else{
                mp[x]-=2;
                s+=2;
                px.push_back(x);
                for(auto ind:imp[x]){
                    stk[ind].pop();
                    if(stk[ind].empty()){
                        continue;
                    }
                    mp[stk[ind].top()]++;
                    imp[stk[ind].top()].insert(ind);
                    if(mp[stk[ind].top()]==2){
                        nx.push_back(stk[ind].top());
                    }
                }
            }
        }
        int k=nx.size();
        for(int i=0;i<k;i++){
            st.insert(nx[i]);
        }
        int l=px.size();
        for(int i=0;i<l;i++){
            st.erase(px[i]);
        }
    }
    if(s==2*n){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}