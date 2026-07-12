#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin>>n>>d;
  vector<int> t(n),l(n);
  for(int i=0;i<n;i++)cin>>t[i]>>l[i];
  for(int k=1;k<=d;k++){
    int ma=0;
    for(int j=0;j<n;j++){
      ma=max(ma,t[j]*(l[j]+k));
    }
    cout<<ma<<endl;
  }
  return 0;
}