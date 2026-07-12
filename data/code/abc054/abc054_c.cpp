#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
int main(){
	int n,m;
	std::cin>>n>>m;
	std::vector<std::vector<int>> g(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		std::cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	std::vector<int> p(n);
	// #include<numeric>
	std::iota(p.begin(),p.end(),1);
	int ans=0;
	do{
		bool isOk=true;
		for(int i=0;i<n-1;i++){
			//use p[i],p[i+1]
			if(std::find(g[p[i]].begin(),g[p[i]].end(),p[i+1])==g[p[i]].end()){
				isOk=false;
			}
		}
		if(isOk){
			ans++;
		}
	}while(std::next_permutation(p.begin(),p.end())&&p[0]==1);
	std::cout<<ans<<'\n';
	return 0;
}