#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a,b;cin>>a>>b;
    vector<int> cnt(3);
    vector<int> p(n);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++){
        if(p[i]<=a)cnt[0]++;
        if(p[i]>=a+1&&p[i]<=b)cnt[1]++;
        if(p[i]>=b+1)cnt[2]++;
    }
    cout<<min({cnt[0],cnt[1],cnt[2]})<<endl;
    return 0;
}