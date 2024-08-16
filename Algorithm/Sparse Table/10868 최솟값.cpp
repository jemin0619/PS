//https://www.acmicpc.net/problem/10868
//Sparse Table은 min, max, gcd (sum 제외) 연산을 O(1)에 수행할 수 있다.
//sum은 O(log N)에 가능하다.
//세그먼트 트리를 써도 되지만 업데이트가 없는 연산에서는 Sparse Table이 더 빠르다. (큰 차이가 없긴 함)

//min max gcd lcm 연산은 범위가 겹쳐도 되는 연산이기에 O(1)에 처리해도 되는데, 범위가 겹치면 안되는 sum 연산은 O(log N) 시간이 걸린다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

////////////////////////////////////////////////////
vector<vector<int>> value;
vector<int> H;

void init(vector<int>&V, int N){
	H.resize(N+1);
	H[1] = 0;
	for(int i=2; i<H.size(); i++){
		H[i] = H[i>>1] + 1;
	}

	value.resize(H.back()+1, vector<int>(N));

	for(int i=0; i<N; i++) value[0][i] = V[i];
	for(int i=1, step=1; i<value.size(); i++, step<<=1){
		auto&prev = value[i-1];
		auto&curr = value[i];
		for(int j=0; j<N; j++){
			if(j+step < N) curr[j] = min(prev[j], prev[j+step]);
			else curr[j] = prev[j];
		}
	}
}

int query(int left, int right){
	int k = H[right-left+1];
	return min(value[k][left], value[k][right+1-(1<<k)]);
}
////////////////////////////////////////////////////

int main(){
	fastio;
	int N, M; cin>>N>>M;
	vector<int> V(N);
	for(int i=0; i<N; i++) cin>>V[i];

	init(V, N);

	while(M--){
		int a, b; cin>>a>>b;
		cout<<query(a-1, b-1)<<'\n';
	}
	return 0;
}
