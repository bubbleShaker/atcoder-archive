#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<long long> dx={1,0,-1,0};
    vector<long long> dy={0,-1,0,1};
    int n,q;cin>>n>>q;
    int t=0;
    vector<pair<long long,long long>> pVec;
    pair<long long,long long> p;
    p.first=1;
    p.second=0;
    pVec.push_back(p);
    while(q--){
        int num;cin>>num;
        if(num==1){
            char c;cin>>c;
            int type;
            if(c=='R')type=0;
            if(c=='D')type=1;
            if(c=='L')type=2;
            if(c=='U')type=3;
            p.first+=dx[type];
            p.second+=dy[type];
            pVec.push_back(p);
            t++;
        }
        if(num==2){
            int P;cin>>P;
            if(t-(P-1)<0){
                cout<<abs(t-(P-1))+1<<" "<<0<<endl;
            }else{
                cout<<pVec[t-(P-1)].first<<" "<<pVec[t-(P-1)].second<<endl;
            }
        }
    }
    return 0;
}