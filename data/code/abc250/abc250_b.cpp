#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;cin>>n>>a>>b;
    vector ans(a*n,vector<char>(b*n));
    for(int i=0;i<a*n;i++){
        for(int j=0;j<b*n;j++){
            if((i/a+j/b)%2==0){
                ans[i][j]='.';
            }else{
                ans[i][j]='#';
            }
        }
    }
    for(int i=0;i<a*n;i++){
        for(int j=0;j<b*n;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}