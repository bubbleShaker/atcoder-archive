#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int n;cin>>n;
    vector<string> s(n),t(n);
    set<string> stringSet;
    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i];
        stringSet.insert(s[i]);
        stringSet.insert(t[i]);
    }
    map<string,int> stringMap;
    int ind=0;
    for(string str:stringSet){
        stringMap[str]=ind;
        ind++;
    }
    int m=stringSet.size();
    dsu uf(m);
    for(int i=0;i<n;i++){
        if(uf.same(stringMap[s[i]],stringMap[t[i]])){
            cout<<"No"<<endl;
            return 0;
        }
        uf.merge(stringMap[s[i]],stringMap[t[i]]);
    }
    cout<<"Yes"<<endl;
    return 0;
}