//좌표압축, 순열 사이클 분할

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second 

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);

  //X순으로 정렬
  int N; cin>>N;
  vector<pair<int,int>> V(N);
  for(int i=0; i<N; i++){
    cin>>V[i].ff>>V[i].ss;
  }
  sort(V.begin(), V.end());

  //Y축을 X축이 작은 순으로 넣음
  vector<int> Y;
  for(int i=0; i<N; i++){
    Y.push_back(V[i].ss);
  }

  //Y축 좌표압축
  vector<int> tmp(Y);
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  for(int&val : Y) val = lower_bound(tmp.begin(), tmp.end(), val) - tmp.begin();
  
  //순열 사이클 분할로 최소 swap 횟수 구하기
  int cycle = 0;
  vector<bool> vis(N);
  for(int i=0; i<N; i++){
    if(vis[i]) continue;
    cycle++;
    for(int nxt=i; !vis[nxt]; nxt=Y[nxt]){
        vis[nxt] = true;
    }
  }

  //N - cycle 개수가 최소 swap 횟수
  cout<< N - cycle;
  return 0;
}
