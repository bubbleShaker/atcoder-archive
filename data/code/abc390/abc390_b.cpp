#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin>>n;
  vector<double> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  double r=a[1]/a[0];
  vector<double> sa(n);
  sa[0]=a[0];
  for(int i=1;i<n;i++){
    sa[i]=r*sa[i-1];
  }
  if(a==sa){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}