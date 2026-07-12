#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> count(n);
    vector<long long> copyA;
    set<int> setA;
    for(int i=0;i<n;i++){
        setA.insert(a[i]);
    }
    for(long long val:setA){
        copyA.push_back(val);
    }
    for(int i=0;i<n;i++){
        int ind=lower_bound(copyA.begin(),copyA.end(),a[i])-copyA.begin();
        count[(int)copyA.size()-ind-1]++;
    }
    for(int i=0;i<n;i++){
        cout<<count[i]<<endl;
    }
    return 0;
}