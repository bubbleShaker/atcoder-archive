#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    while(1){
        bool isChanged=false;
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                a[i]/=2;
                ans++;
                isChanged=true;
            }
        }
        if(isChanged==false)break;
    }
    cout<<ans<<endl;
    return 0;
}