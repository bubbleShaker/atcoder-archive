#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<long long,long long>> Point;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        Point.push_back({x,y});
    }
    string s;cin>>s;
    map<long long,vector<pair<long long,char>>> mapY;
    for(int i=0;i<n;i++){
        mapY[Point[i].second].push_back({Point[i].first,s[i]});
    }
    for(auto [y,pairVec]:mapY){
        bool isRChecked=false;
        sort(pairVec.begin(),pairVec.end());
        for(auto [x,direction]:pairVec){
            if(direction=='R')isRChecked=true;
            else if(direction=='L'){
                if(isRChecked){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}