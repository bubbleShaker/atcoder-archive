#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(10);
  for(int i=0;i<10;i++){
    cin>>a[i];
  }
  int k=0;
  cout<<a[a[a[k]]]<<endl;
  return 0;
}