#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<tuple<int,int,int>> tplVec(n);
    for(int i=0;i<n;i++){
        int t,l,r;cin>>t>>l>>r;
        tplVec[i]={t,l,r};
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            auto [ti,li,ri]=tplVec[i];
            auto [tj,lj,rj]=tplVec[j];
            int t1,l1,r1,t2,l2,r2;
            if(li==lj){
                ans++;
                continue;
            }else if(li<lj){
                t1=ti;
                l1=li;
                r1=ri;
                t2=tj;
                l2=lj;
                r2=rj;
            }else{
                t1=tj;
                l1=lj;
                r1=rj;
                t2=ti;
                l2=li;
                r2=ri;
            }
            if(l1<l2&&r2<r1)ans++;
            else if(l1<l2&&l2<r1)ans++;
            else if(r1==l2){
                if(t1==2||t1==4||t2==3||t2==4)continue;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}