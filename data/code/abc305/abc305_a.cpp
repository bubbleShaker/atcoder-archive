#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> vec;
    for(int i=0;i<=100;i+=5){
        vec.push_back(i);
    }
    int ind=lower_bound(vec.begin(),vec.end(),n)-vec.begin();
    if(ind==0){
        cout<<0<<endl;
        return 0;
    }
    if(abs(vec[ind-1]-n)<abs(vec[ind]-n)){
        cout<<vec[ind-1]<<endl;
    }else{
        cout<<vec[ind]<<endl;
    }
    return 0;
}