#include <iostream>
#include <vector>
#include <bitset>
int main(){
	int n,m,k;
	std::cin>>n>>m>>k;
	std::vector<std::vector<int>> a(m);
	std::vector<int> c(m);
	std::vector<char> r(m);
	for(int i=0;i<m;i++){
		std::cin>>c[i];
		for(int j=0;j<c[i];j++){
			int val;
			std::cin>>val;
			val--;
			a[i].push_back(val);
		}
		std::cin>>r[i];
	}
	int ans=0;
	for(int bit=0;bit<(1<<n);bit++){
		std::bitset<16> bitset(bit);
		//リファレンス:https://cpprefjp.github.io/reference/bitset/bitset.html
		//雑メモ:std::coutで2進法表記で出力
		//整数から10ビットのビット集合を構築
		//bitset<10> bs(5)
		//論理和、論理積、排他的論理和もサポートしている
		//* []で任意のビットにアクセス、countで1になっているビットの数を取得など
		//! 注意:sizeは定数でしか指定できないため、十分なサイズを定義する
		//! 注意:bitset.count()は返り値の型がstd::size_t(?)なのでintにキャストして使用しないとエラーになる
		//! 注意:ビットへのアクセスは0-indexed
		bool isOk=true;
		for(int i=0;i<m;i++){
			int cnt=0;
			for(int j=0;j<c[i];j++){
				if(bitset[a[i][j]]){
					cnt++;
				}
			}
			if(r[i]=='o'&&cnt<k){
				isOk=false;
			}else if(r[i]=='x'&&cnt>=k){
				isOk=false;
			}
		}
		if(isOk){
			ans++;
		}
	}
	std::cout<<ans<<'\n';
	return 0;
}