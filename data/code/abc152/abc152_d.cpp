#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int n;cin>>n;
    map<pair<int,int>,int> pairMap;
    int ans=0;
    auto keta=[&](int val){
        int res=0;
        while(val>0){
            val/=10;
            res++;
        }
        return res;
    };
    auto toInt=[&](vector<int> vec){
        int res=0;
        int m=vec.size();
        for(int i=0;i<m;i++){
            res*=10;
            res+=vec[i];
        }
        return res;
    };
    auto dfs=[&](auto dfs,int i,int j,int k,vector<int> valVec)->void{
        if(valVec.size()==0){
            valVec.push_back(i);
            dfs(dfs,i,j,k,valVec);
            return;
        }
        if(valVec.size()==k-1){
            valVec.push_back(j);
            if(toInt(valVec)<=n){
                pairMap[{i,j}]++;
                // cout<<toInt(valVec)<<endl;
            }
            return;
        }
        for(int l=0;l<=9;l++){
            valVec.push_back(l);
            dfs(dfs,i,j,k,valVec);
            valVec.pop_back();
        }
    };
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i==j&&i<=n){
                pairMap[{i,j}]++;
                // cout<<i<<endl;
            }
            // cout<<i<<" "<<j<<endl;
            if(n>=10){
                for(int k=2;k<=keta(n);k++){
                    // cout<<k<<endl;
                    vector<int> valVec;
                    dfs(dfs,i,j,k,valVec);
                }
            }
        }
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=pairMap[{i,j}]*pairMap[{j,i}];
        }
    }
    cout<<ans<<endl;
    return 0;
}