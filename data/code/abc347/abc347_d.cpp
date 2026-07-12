#include <bits/stdc++.h>
using namespace std;
long long pop_count(long long n){
    return __builtin_popcountll(n);
}
long long toLL(vector<long long> v){
    long long ans=0;
    long long ret=1;
    long long power=0;
    long long n=v.size();
    for(long long i=0;i<n;i++){
        while(v[i]>power){
            ret*=2;
            power++;
        }
        ans+=ret;
    }
    return ans;
}
int main() {
    long long a,b,C;
    cin>>a>>b>>C;
    long long c=pop_count(C);
    pair<long long,long long> p1={61-a,a},p2={61-b,b};
    long long m=min(p1.second,p2.second);
    for(long long i=0;i<=m;i++){
        p1.second-=i;
        p2.second-=i;
        long long cnt=min(p1.first,p2.second)+min(p2.first,p1.second);
        if(c==cnt){
            long long rcnt=i;
            long long ni=0;
            vector<long long> xb,yb;
            for(long long j=0;(1LL<<j)<=C;j++){
                if((1LL<<j)&C){
                    if(p1.second>0){
                        xb.push_back(j);
                        p1.second--;
                        p2.first--;
                    }else{
                        yb.push_back(j);
                        p2.second--;
                        p1.first--;
                    }
                    ni=j+1;
                }else{
                    if(rcnt>0){
                        xb.push_back(j);
                        yb.push_back(j);
                        rcnt--;
                    }
                }
            }
            // cout<<ni<<endl;
            // cout<<rcnt<<endl;
            for(long long j=0;j<rcnt;j++){
                xb.push_back(ni+j);
                yb.push_back(ni+j);
            }
            long long x=toLL(xb),y=toLL(yb);
            cout<<x<<" "<<y<<endl;
            return 0;
        }
        p1.second+=i;
        p2.second+=i;
    }
    cout<<-1<<endl;
    return 0;
}