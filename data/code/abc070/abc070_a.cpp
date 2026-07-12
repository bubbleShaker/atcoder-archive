#include <bits/stdc++.h>
using namespace std;

vector<int> toVec(int val){
    vector<int> res;
    while(val>0){
        res.push_back(val%10);
        val/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> vec=toVec(n);
    for(int i=0;i<3;i++){
        if(vec[i]!=vec[3-i-1]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}