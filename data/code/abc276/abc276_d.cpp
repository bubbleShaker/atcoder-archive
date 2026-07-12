#include <bits/stdc++.h>
using namespace std;

bool isOk(int val){
    bool res=true;
    for(int i=1;i*i<=val;i++){
        if(val%i==0){
            int a=val/i;
            if(i%2!=0&&i%3!=0&&i!=1)res=false;
            if(a%2!=0&&a%3!=0&&a!=1)res=false;
        }
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    bool isAllSame=true;
    int saidaiKoyakusu=a[0];
    for(int i=0;i<n;i++){
        saidaiKoyakusu=gcd(saidaiKoyakusu,a[i]);
    }
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1])isAllSame=false;
    }
    for(int i=0;i<n;i++){
        a[i]/=saidaiKoyakusu;
    }
    for(int i=0;i<n;i++){
        if(isOk(a[i])==false){
            cout<<-1<<endl;
            return 0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        while(a[i]!=1){
            if(a[i]%2==0){
                ans++;
                a[i]/=2;
            }
            if(a[i]%3==0){
                ans++;
                a[i]/=3;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}