#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long a,b;
    string s;
    cin>>n>>a>>b>>s;
    long long ans=(long long)2*1e18;
    for(int i=0;i<n;i++){
        long long sum=i*a;
        int bCount=0;
        for(int j=0;j<(n/2);j++){
            if(s[j]!=s[n-j-1])bCount++;
        }
        sum+=b*bCount;
        ans=min(ans,sum);
        rotate(s.begin(),s.begin()+1,s.end());
    }
    cout<<ans<<endl;
    return 0;
}