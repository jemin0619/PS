### [추천 글 1](https://ps.mjstudio.net/permutation-cycle-decomposition)
### [추천 글 2](https://00ad-8e71-00ff-055d.tistory.com/57)

# 순열 사이클 분할이란
  - 모든 원소가 인덱스 번호를 가리키는 순열에서 사이클의 개수를 구하는 기법이다.
  - 좌표압축을 사용해 각 원소가 인덱스를 가리키도록 해줄 수 있다.
  - [수열이 정렬되기 위한 최소 swap 횟수](https://dong-gas.tistory.com/84)
    - N - Cycle개수 로 나타낼 수 있다.

###  

## [BOJ 10451 순열 사이클](https://www.acmicpc.net/problem/10451)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        vector<int> V(N+1);
        vector<bool> vis(N+1);
        int cnt = 0;
        for(int i=1;i<=N;i++) cin>>V[i];
        for(int i=1;i<=N;i++){
            if(vis[i]) continue;
            cnt++;
            for(int nxt=i; !vis[nxt]; nxt=V[nxt]){
                vis[nxt] = true;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
```
</details>

- 순열 사이클의 개수 세기

###  

## [BOJ 25577 열 정렬정렬 정](https://www.acmicpc.net/problem/25577)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//좌압 + 순싸분 + 그리디
//서로 다른 N개의 원소를 swap으로 정렬하려면 최소 N - cycle개수 번 swap해야 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

void compress(vector<int>&V){
    vector<int> tmp(V);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int&val : V) val=lower_bound(tmp.begin(), tmp.end(),val)-tmp.begin();
}

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N);
    for(int i=0;i<N;i++) cin>>V[i];
    compress(V);
    vector<bool> vis(N);
    int cycle = 0;
    for(int i=0;i<N;i++){
        if(vis[i]) continue;
        cycle++;
        for(int nxt=i; !vis[nxt]; nxt=V[nxt]){
            vis[nxt] = true;
        }
    }
    cout<<N - cycle;
    return 0;
}
```
</details>

- 좌표압축을 곁들인 순열 사이클 분할
- 수열이 정렬되기 위한 최소 swap 횟수 구하기

###  

## [BOJ 25614 자리 바꾸기](https://www.acmicpc.net/problem/25614)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//bigint 구현체는 생략한다.
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    string m;
    int N; cin>>N>>m;
    bigint M(m);
    vector<int> V(N+1);
    vector<bool> vis(N+1);
    vector<int> Ans(N+1, -1);
    vector<int> memo(N, -1); //mod값 저장해둠
    for(int i=1;i<=N;i++) cin>>V[i];
    for(int i=1;i<=N;i++){
        if(Ans[i]!=-1) continue;
        int l = 0;
        for(int nxt=i; !vis[nxt]; nxt=V[nxt]){
            vis[nxt]=true;
            l++;
        }
        int move;
        if(memo[l]!=-1) move = memo[l];
        else move = memo[l] = bigint(m)%l;
        int next = i;
        for(int j=0; j<move; j++){
            next = V[next];
        }
        Ans[i] = next;

        int cur = V[i];
        int nxt = V[next];
        for(;Ans[cur]==-1;cur=V[cur],nxt=V[nxt]){
            Ans[cur] = nxt;
        }
    }
    for(int i=1;i<=N;i++) cout<<Ans[i]<<' ';
    return 0;
}
```
</details>

- Bigint 연산은 수가 커질수록 연산도 무거워지므로 연산 결과를 저장해주는게 좋다.

###  
