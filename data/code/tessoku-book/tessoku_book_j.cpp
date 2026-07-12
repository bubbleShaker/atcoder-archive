#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<int> rsmax1(n+2),rsmax2(n+2);//1…左から,2…右から
  for(int i=1;i<=n;i++){
    rsmax1[i]=max(rsmax1[i-1],a[i]);
  }
  for(int i=n;i>=1;i--){
    rsmax2[i]=max(rsmax2[i+1],a[i]);
  }
  int d;
  cin>>d;
  for(int i=0;i<d;i++){
    int l,r;
    cin>>l>>r;
    cout<<max(rsmax1[l-1],rsmax2[r+1])<<'\n';
  }
  return 0;
}