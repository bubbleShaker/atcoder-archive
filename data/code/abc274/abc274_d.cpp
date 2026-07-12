#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<int,bool> mpx,mpy;
    mpx[a[1]]=true;
    mpy[0]=true;
    for(int i=2;i<=n;i++){
        if(i%2==0)continue;
        map<int,bool> mp;
        for(int j=-10000;j<=10000;j++){
            if(mpx.count(j-a[i])){
                mp[j]=true;
            }
            if(mpx.count(j+a[i])){
                mp[j]=true;
            }
        }
        mpx=mp;
    }
    for(int i=2;i<=n;i++){
        if(i%2==1)continue;
        map<int,bool> mp;
        for(int j=-10000;j<=10000;j++){
            if(mpy.count(j-a[i])){
                mp[j]=true;
            }
            if(mpy.count(j+a[i])){
                mp[j]=true;
            }
        }
        mpy=mp;
    }
    if(mpx.count(x)&&mpy.count(y)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}