#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
int main(){
  std::vector<int> a(3),ca;
  for(int i=0;i<3;i++){
    std::cin>>a[i];
  }
  ca=a;
  std::sort(a.rbegin(),a.rend());
  a.erase(std::unique(a.begin(),a.end()),a.end());
  //unique…https://cpprefjp.github.io/reference/algorithm/unique.html
  //* unique…[first,last)から重複した要素を取り除ける。隣り合った重複要素を除いた要素を、範囲の先頭に集める。
  //* コンテナから実際に要素を削除する場合、関数の戻り値として、先頭に集められた重複なし範囲の末尾の次を指すイテレータが返るため、コンテナのerase()メンバ関数などを呼び出し、削除を行う。
  //erase…https://cpprefjp.github.io/reference/vector/vector/erase.html
  //* erase…[first,last)で示されるイテレータ範囲の要素が削除される。
  std::vector<int> ans;
  for(int i=0;i<3;i++){
    for(int j=0;j<a.size();j++){
      if(ca[i]==a[j]){
        ans.push_back(j+1);
        break;
      }
    }
  }
  for(int i=0;i<3;i++){
    std::cout<<ans[i]<<'\n';
  }
  return 0;
}