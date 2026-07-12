#include <bits/stdc++.h>
using namespace std;

int toInt(vector<int> vec){
    int n=vec.size();
    int res=0;
    for(int i=0;i<n;i++){
        res*=10;
        res+=vec[i];
    }
    return res;
}

int main(){
    string s;cin>>s;
    vector<vector<int>> vec(3);
    vector<int> ymd(3);
    int n=s.size();
    int ind=0;
    for(int i=0;i<n;i++){
        if(s[i]=='/')ind++;
        else vec[ind].push_back(s[i]-'0');
    }
    for(int i=0;i<3;i++){
        ymd[i]=toInt(vec[i]);
    }
    if(ymd[0]<=2019){
        if(ymd[1]<=4){
            if(ymd[2]<=30){
                cout<<"Heisei"<<endl;
                return 0;
            }
        }
    }
    cout<<"TBD"<<endl;
    return 0;
}