#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;cin>>h>>w;
    vector<vector<int>> a(h,vector<int>(w));
    int minVal=(int)1e9;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            minVal=min(minVal,a[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            ans+=a[i][j]-minVal;
        }
    }
    cout<<ans<<endl;
    return 0;
}