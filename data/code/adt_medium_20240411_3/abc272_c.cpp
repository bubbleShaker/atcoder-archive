#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> evens,odds;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a%2==0){
            evens.push_back(a);
        }else{
            odds.push_back(a);
        }
    }
    sort(evens.rbegin(),evens.rend());
    sort(odds.rbegin(),odds.rend());
    int m=evens.size();
    int k=odds.size();
    int ans=-1;
    if(m>=2){
        ans=max(ans,evens[0]+evens[1]);
    }
    if(k>=2){
        ans=max(ans,odds[0]+odds[1]);
    }
    cout<<ans<<endl;
    return 0;
}