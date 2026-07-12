#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
int n,m;

void dfs(vector<int> a){
  int las=a[a.size()-1];
  if(las>m) return;//一番最後がmを超えていたら処理終了
  int rem=n-a.size();//残りの数列の長さ
  int mi=rem*10;//最小の増分
  if(las+mi>m) return;//現時点で最小の遷移を辿っても無理なら処理終了
  if(a.size()==n){
    ans.push_back(a);
    return;
  }
  for(int i=10;i<=m;i++){
    a.push_back(las+i);
    dfs(a);
    a.pop_back();
  }
  return;
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    vector<int> a;
    a.push_back(i);
    dfs(a);//コピーを渡す
  }
  int cou=ans.size();
  cout<<cou<<endl;
  for(auto vec:ans){
    for(int i=0;i<n;i++){
      cout<<vec[i]<<" ";
    }cout<<endl;
  }
  return 0;
}