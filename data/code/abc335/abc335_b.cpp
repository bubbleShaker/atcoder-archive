#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<tuple<int,int,int>> tplVec;
    for(int x=0;x<=n;x++){
        for(int y=0;y<=n;y++){
            for(int z=0;z<=n;z++){
                if(x+y+z>n)continue;
                tplVec.push_back({x,y,z});
            }
        }
    }
    auto f=[&](tuple<int,int,int> tpl1,tuple<int,int,int> tpl2){
        auto [x1,y1,z1]=tpl1;
        auto [x2,y2,z2]=tpl2;
        if(x1==x2){
            if(y1==y2){
                return z1<z2;
            }else{
                return y1<y2;
            }
        }else{
            return x1<x2;
        }
    };
    sort(tplVec.begin(),tplVec.end(),f);
    for(auto [x,y,z]:tplVec){
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    return 0;
}