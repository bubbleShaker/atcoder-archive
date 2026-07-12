#include <bits/stdc++.h>
using namespace std;

int main(){
  int n=5;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> pa={1,2,3,4,5};
  for(int i=0;i<n-1;i++){
    vector<int> ca=a;
    swap(ca[i],ca[i+1]);
    if(ca==pa){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}