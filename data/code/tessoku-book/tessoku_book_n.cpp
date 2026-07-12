#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector a(4,vector<int>(n));
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<int> fVec,sVec;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fVec.push_back(a[0][i]+a[1][j]);
            sVec.push_back(a[2][i]+a[3][j]);
        }
    }
    sort(fVec.begin(),fVec.end());
    sort(sVec.begin(),sVec.end());
    // for(int i=0;i<fVec.size();i++){
    //     cout<<fVec[i]<<" \n"[i+1==fVec.size()];
    // }
    // for(int i=0;i<sVec.size();i++){
    //     cout<<sVec[i]<<" \n"[i+1==sVec.size()];
    // }
    int m=fVec.size();
    for(int i=0;i<m;i++){
        int ind=lower_bound(sVec.begin(),sVec.end(),k-fVec[i])-sVec.begin();
        if(fVec[i]+sVec[ind]==k){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}