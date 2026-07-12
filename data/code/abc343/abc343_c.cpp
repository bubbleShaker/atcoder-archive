#include <bits/stdc++.h>
using namespace std;
vector<long long> toVec(long long val){
    vector<long long> ret;
    while(val>0){
        ret.push_back(val%10);
        val/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
bool isKaibun(long long val){
    vector<long long> vec=toVec(val);
    int n=vec.size();
    for(int i=0;i<n;i++){
        if(vec[i]!=vec[n-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    long long n;
    cin>>n;
    vector<long long> vec;
    for(long long i=1;i*i*i<=n;i++){
        vec.push_back(i*i*i);
    }
    long long ans=0;
    int m=vec.size();
    for(int i=0;i<m;i++){
        if(isKaibun(vec[i])){
            ans=max(ans,vec[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}