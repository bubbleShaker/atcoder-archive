#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,d;cin>>m>>d;
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=22;j<=d;j++){
            int a=j/10,b=j%10;
            if(a<2||b<2)continue;
            if(a*b==i)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}