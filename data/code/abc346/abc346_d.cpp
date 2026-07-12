#include <bits/stdc++.h>
using namespace std;
int main(){
    const long long INF=(long long)1e18;
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    string s="_";
    s+=ss;
    vector<long long> c(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    vector<long long> mrwz(n+2),mrwo(n+2),lrwz(n+2),lrwo(n+2);
    if(s[1]=='1'){
        mrwz[1]=c[1];
    }else{
        mrwo[1]=c[1];
    }
    for(int i=2;i<=n;i++){
        int c0=0,c1=0;
        if(s[i]=='0'){
            c1=c[i];
        }else{
            c0=c[i];
        }
        mrwo[i]+=mrwz[i-1]+c1;
        mrwz[i]+=mrwo[i-1]+c0;
    }
    if(s[n]=='1'){
        lrwz[n]=c[n];
    }else{
        lrwo[n]=c[n];
    }
    for(int i=n-1;i>=1;i--){
        int c0=0,c1=0;
        if(s[i]=='0'){
            c1=c[i];
        }else{
            c0=c[i];
        }
        lrwo[i]+=lrwz[i+1]+c1;
        lrwz[i]+=lrwo[i+1]+c0;
    }
    long long ans=INF;
    for(int i=1;i<=n-1;i++){
        long long zc1=0,zc2=0,oc1=0,oc2=0;
        if(s[i]=='0'){
            oc1=c[i];
        }else{
            zc1=c[i];
        }
        if(s[i+1]=='0'){
            oc2=c[i+1];
        }else{
            zc2=c[i+1];
        }
        long long mi=min(zc1+zc2+mrwo[i-1]+lrwo[i+2],oc1+oc2+mrwz[i-1]+lrwz[i+2]);
        ans=min(ans,mi);
    }
    cout<<ans<<endl;
    return 0;
}