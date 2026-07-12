#include <bits/stdc++.h>
using namespace std;
bool f(pair<int,int> p1,pair<int,int> p2){
    auto [x1,y1]=p1;
    auto [x2,y2]=p2;
    if(x1==x2){
        return y1>y2;
    }else{
        return x1<x2;
    }
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> pVec(n+1);
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        pVec[i]={x,y};
    }
    sort(pVec.begin(),pVec.end(),f);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        a[i]=pVec[i].second;
    }
    vector<int> dp(n+1);
    vector<int> l(n+1);
    int len=0;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(l.begin()+1,l.begin()+len+1,a[i])-l.begin();
        dp[i]=pos;
        l[pos]=a[i];
        if(pos>len){
            len++;
        }
    }
    cout<<len<<endl;
    return 0;
}