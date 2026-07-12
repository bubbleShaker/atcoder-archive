#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    
    auto f1=[&](int x,int y){
        if(y+5>=n)return false;
        int whiteCount=0;
        for(int j=y;j<=y+5;j++){
            if(s[x][j]=='.')whiteCount++;
        }
        return whiteCount<=2;
    };
    
    auto f2=[&](int x,int y){
        if(x+5>=n||y+5>=n)return false;
        int whiteCount=0;
        for(int i=0;i<=5;i++){
            if(s[x+i][y+i]=='.')whiteCount++;
        }
        return whiteCount<=2;
    };
    
    auto f3=[&](int x,int y){
        if(x+5>=n)return false;
        int whiteCount=0;
        for(int i=x;i<=x+5;i++){
            if(s[i][y]=='.')whiteCount++;
        }
        return whiteCount<=2;
    };
    
    auto f4=[&](int x,int y){
        if(x+5>=n||y-5<0)return false;
        int whiteCount=0;
        for(int i=0;i<=5;i++){
            if(s[x+i][y-i]=='.')whiteCount++;
        }
        return whiteCount<=2;
    };
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(f1(i,j)||f2(i,j)||f3(i,j)||f4(i,j)){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}