#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int sum=0;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  if(sum>m)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}