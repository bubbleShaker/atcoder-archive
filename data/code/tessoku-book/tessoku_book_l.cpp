#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    auto f=[&](int sec){
        long long ret=0;
        for(int i=0;i<n;i++){
            ret+=((long long)sec/a[i]);
        }
        return ret;
    };
    int ng=0,ok=(int)1e9;
    while(abs(ng-ok)>1){
        int mid=(ok+ng)/2;
        if(f(mid)<(long long)k){
            ng=mid;
        }else{
            ok=mid;
        }
    }
    cout<<ok<<endl;
    return 0;
}