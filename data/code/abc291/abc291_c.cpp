#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;cin>>s;
    int x=0,y=0;
    map<pair<int,int>,int> pointMap;
    pointMap[{x,y}]++;
    for(int i=0;i<n;i++){
        if(s[i]=='R')x++;
        if(s[i]=='L')x--;
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;
        pointMap[{x,y}]++;
    }
    for(auto [point,count]:pointMap){
        if(count>1){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}