#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    int val=-1;
    while(val!=0){
        cin>>val;
        a.push_back(val);
    }
    int n=a.size();
    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<endl;
    }
    return 0;
}