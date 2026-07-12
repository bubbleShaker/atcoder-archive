#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> p(n+1);
    bool isShojun=false;
    int ind1;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        if(p[i]==1){
            ind1=i+1;
        }
    }
    int sum=0;
    for(int i=0;i<2*n-1;i++){
        if(p[(i+1)%n]-p[i%n]>0)sum++;
        else sum--;
    }
    if(sum>0){
        isShojun=true;
    }
    int ans;
    if(isShojun){
        ans=min(ind1-1,n-ind1+3);
    }else{
        ans=min(ind1+1,n-ind1+1);
    }
    cout<<ans<<endl;
    return 0;
}