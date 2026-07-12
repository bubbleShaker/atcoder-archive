#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rot(vector<vector<int>> a){
  int n=a.size();
  vector ret(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ret[i][j]=a[n-j-1][i];
    }
  }
  return ret;
}

void out(vector<vector<int>> a){
  int n=a.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool check(vector<vector<int>> a,vector<vector<int>> b){
  int n=a.size();
  bool ret=true;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]==1&&b[i][j]==0){
        ret=false;
      }
    }
  }
  return ret;
}

int main(){
  int n;
  cin>>n;
  vector a(n,vector<int>(n));
  vector b(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>b[i][j];
    }
  }
  vector<vector<int>> ret=a;
  for(int i=0;i<4;i++){
    ret=rot(a);
    a=ret;
    if(check(a,b)){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}