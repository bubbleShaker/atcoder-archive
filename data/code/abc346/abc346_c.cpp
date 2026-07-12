#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    set<long long> st;
    long long as=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(st.count(a[i])==false&&a[i]<=k){
            as+=a[i];
        }
        st.insert(a[i]);
    }
    long long s=k*(k+1)/2;
    cout<<s-as<<endl;
    return 0;
}