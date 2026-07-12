#include <iostream>
#include <cmath>
int main(){
  long long sx,sy,tx,ty;
  std::cin>>sx>>sy>>tx>>ty;
  //タイルの左下の座標に合わせて考える
  if(sy%2==0){ //列が偶数番目だったら
    if(sx%2){
      sx--; //奇数だったら1左に
    }
  }else if(sy%2){ //列が奇数番目だったら
    if(sx%2==0){ //偶数番目だったら
      sx--; //1減らす
    }
  }
  if(ty%2==0){ //列が偶数番目だったら
    if(tx%2){
      tx--; //奇数だったら1左に
    }
  }else if(ty%2){ //列が奇数番目だったら
    if(tx%2==0){ //偶数番目だったら
      tx--; //1減らす
    }
  }
  long long dx=std::abs(sx-tx);
  long long dy=std::abs(sy-ty);
  if(dx<=dy){ //縦移動だけで完了すると仮定
    std::cout<<dy<<'\n';
  }else{
    std::cout<<dy+(dx-dy)/2<<'\n';
  }
  return 0;
}