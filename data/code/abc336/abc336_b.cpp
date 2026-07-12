#include <bits/stdc++.h>
using namespace std;
vector<int> toBin(int n){
    vector<int> res;
    while(n>0){
        res.push_back(n%2);
        n/=2;
    }
    return res;
}
int main(){
    int n;cin>>n;
    vector<int> binary=toBin(n);
    int ans=0;
    int m=binary.size();
    for(int i=0;i<m;i++){
        if(binary[i]==1)break;
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}