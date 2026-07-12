#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> p(n);
  for(int i=0;i<n;i++)cin>>p[i];
  prev_permutation(p.begin(),p.end());
  for(int i=0;i<n;i++){
    cout<<p[i]<<" ";
  }cout<<endl;
  return 0;
}