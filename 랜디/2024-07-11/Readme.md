### [A Cedric's Cypher B2](https://www.acmicpc.net/problem/9954)

### [B 영어 시험 S4](https://www.acmicpc.net/problem/25288)

### [C Density Map S3](https://www.acmicpc.net/problem/8029)

### [D Longest Palindrome S1](https://www.acmicpc.net/problem/24832)

### [E 한강 (Small) S1](https://www.acmicpc.net/problem/12435)

### [F Not Equal G5](https://www.acmicpc.net/problem/14926)

### [G 벼락치기 G5](https://www.acmicpc.net/problem/29704)

### [H 과제 G3](https://www.acmicpc.net/problem/13904)

# 학습노트

+ 학습한 내용
  - A : 구현, 문자열
  - B : 애드 훅, 문자열
  - C : 2차원 누적합 DP
  - D : 문자열, 그리디
  - E : 에라토스테네스의 채 응용
  - F : 오일러 경로, DFS, 그리디
  - G : Knapsack DP
  - H : 그리디, 정렬, (분리집합)

+ 총평
  - 문제가 다양하게 나왔다.
  - B는 간단한 애드 훅인데 모든 문자를 다 만드려면 입력받은 문자열을 N번 반복해 출력해주면 된다. 이보다 짧은 문자열은 존재하지 않는다.
  - 2차원 누적합 DP는 간만이라 기억이 잘 안나서 찾아보며 풀었다.
  - 문제 해설이 퍼져있지 않아 쉽지 않은 여정이었다.
  - D는 코포 Div.2에 나왔던 문제라는데 확실히 답은 떠올리기까지 시간이 걸렸다.
  - 문자열의 길이가 모두 같고 입력받는 모든 문자열은 유일하다는 조건 때문에 쉽게 풀린다.
  - E는 답을 보지 않고선 해결할 수 없었다. 에라토스테네스의 채로 소수가 아니라 약수를 구해야 했다.
  - F는 오일러 경로 태그가 있었는데, 문제를 보고 그래프라고 떠올리기도 쉽지 않았고, 답의 마지막에 an a1이 와야 한다는 것을 깨닫기까지 시간이 걸렸다.
  - H는 BOJ 공항 문제에서처럼 분리집합을 이용해 해결했다. 재밌는 문제였다.
  - DP를 더 공부해야 할 것 같다. 그리디는 좀 익숙해졌는데 DP는 너무 힘들다...

+ ## C Density Map
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  
  int board[253][253];
  int W[253][253];
  int dp[253][253];
  
  int main() {
      fastio;
      int n,r; cin>>n>>r;
      for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
              cin>>board[i][j];
  
      //2차원 누적합
      for(int i=1;i<=n;i++){
          dp[i][1] = board[i][1];
          for(int j=2;j<=n;j++){
              dp[i][j] = dp[i][j-1]+board[i][j];
          }
      }
   
      for(int i=2;i<=n;i++){
          for(int j=1;j<=n;j++){
              dp[i][j] += dp[i-1][j];
          } 
      }
           
      for(int i=1; i<=n; i++){
          for(int j=1; j<=n; j++){
              int W = 0;
              W += dp[min(n,i+r)][min(n,j+r)];
              W -= dp[max(i-r-1,0)][min(n,j+r)];
              W -= dp[min(n,i+r)][max(j-r-1,0)];
              W += dp[max(i-r-1,0)][max(j-r-1,0)];
              cout<<W<<' ';
          } cout<<'\n';
      }
      return 0;
  }

  ```
  </details>
  - N^4가 돈다는데 어떻게 커팅한건지 모르겠다...
 
+ ## D Longest Palindrome
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  
  int main(){
      fastio;
      int N, M; cin>>N>>M;
      vector<string> R;
      vector<string> L;
      vector<string> Mid;
      vector<string> V;
      vector<bool> chk(103,false);
      for(int i=0;i<N;i++){
          string x; cin>>x;
          bool is_Pallindrome = true;
          for(int i=0;i<=(x.size()-1)/2;i++){
              if(x[i]!=x[x.size()-1-i]) {is_Pallindrome=false; break;}
          }
          if(!is_Pallindrome) V.push_back(x);
          else Mid.push_back(x);
      }
      for(int i=0;i<V.size();i++){
          if(chk[i]) continue;
          string rev = V[i];
          reverse(rev.begin(),rev.end());
          for(int j=0;j<V.size();j++){
              if(chk[j]) continue;
              if(V[j]==rev){ //해당 문자열에 대응하는 문자열이 존재할 경우
                  R.push_back(V[i]);
                  L.push_back(V[j]);
                  chk[j] = chk[i] =true;
                  break;
              }
          }
      }
      reverse(R.begin(),R.end());
      string Ans = "";
      for(string val : L) Ans+=val;
      if(Mid.size()>=1) Ans+=Mid[0];
      for(string val : R) Ans+=val;
      cout<<Ans.size()<<'\n';
      cout<<Ans;
      return 0;
  }
  
  /*
  Mid에 같은게 두개 이상 있으면 R, L에 사용할 수도 있음
  홀수인 요소만 가운데에 쓰고 나머지는 R,L에 배정해도 된다.
  - 그럴 필요 없음. 모든 문자열은 distinct함.
  */
  ```
  </details>
  
  - BruteForce 

+ ## E 한강 (Small)
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  
  /*
  N과 M이 주어진다.
  2 ~ M까지의 수가 있을 때, N과 약수의 개수가 같은 수 중, 가장 작은 약수가 M보다 같거나 큰 수의 개수를 구하시오.
  (약수의 개수에서 자기 자신은 제외한다.)
  
  에라토스테네스의 채를 응용해야 한다.
  */
  
  vector<int> cnt(1000003,0);
  vector<int> mn(1000003,-1);
  map<int,vector<int>> Mp;
  
  void sieve(){ //에라토스테네스의 채로 전처리
      for(int i=2;i<=1000000/2;i++){
          for(int j=i+i;j<=1000000;j+=i){
              cnt[j]++; //i로 나누어 떨어지게 됨
              if(mn[j]==-1) mn[j]=i;
          }
      }
  
      //Key를 약수의 개수로 가지는 Map에 약수의 개수가 같은 수들을 묶어서 저장함
      for(int i=1;i<=1000000;i++){
          Mp[cnt[i]].push_back(i);
      }
  }
  
  int solve(int N, int M){
      int ret = 0;
      for(auto i : Mp[cnt[N]]){ //약수의 개수가 같은 수들만 돌면서 탐색
          if(i>=N) break;
          if(mn[i]>=M) ret++;
      }   
      return ret;
  }
  
  int main(){
      fastio;
      sieve();
      int t; cin>>t;
      for(int tc=1;tc<=t;tc++){
          int N,M; cin>>N>>M;
          cout<<"Case #"<<tc<<": "<<solve(N,M)<<'\n';
      }
      return 0;
  }
  ```
  </details>

  - 지문이 상당히 더럽다.
  - seive로 약수 개수 구하기
 
+ ## F Not Equal
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  
  /*
  처음에 그래프로 접근한다는 발상조차 하지 못했는데, Hint를 보고서 깨달았다.
  정점이 N개인 완전 그래프를 생성하고 그래프에서 DFS를 돌기만 하면 해결된다.
  
  완전 그래프를 생성하지 않고도 for문으로 순회할 수 있다. (어차피 한 정점은 모든 정점으로 향할 수 있으므로)
  */
  
  int N;
  vector<int> adj[503];
  bool vis[503][503];
  
  void DFS(int cur, int pre){
      vis[pre][cur] = vis[cur][pre] = true;
      cout<<"a"<<cur<<' ';
      for(int nxt : adj[cur]){
          if(vis[cur][nxt] || vis[nxt][cur]) continue;
          DFS(nxt,cur); break;
      }
  }
  
  int main(){
      fastio;
      cin>>N;
      for(int i=1;i<=N;i++){
          for(int j=1;j<=N;j++){
              if(i==j) continue;
              adj[i].push_back(j);
          }
      }
  
      //이렇게 하지 않으면 TC2에서 문제가 생긴다.
      //사전순으로 가장 빠른 답을 출력해야 하므로 마지막 두개는 an a1일 것이다.
      //미리 방문처리를 해줘서 마지막에 방문하도록 해야 한다.
      //이 부분을 도저히 모르겠어서 답을 확인했다.
      vis[1][N] = vis[N][1] = true;
  
      DFS(1,0);
      cout<<"a1";
      return 0;
  }
  ```
  </details>

  - 완전그래프이기에 굳이 그래프를 구성할 필요는 없다.
  - 비재귀로 구현할 수도 있다.
  - 오일러 경로
 
+ ## H 과제 
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //점수가 큰 순으로, 기간이 적은 순으로 정렬하면 될거같음

  /*
  union find로 공항처럼 해결할 수 있음 
  각 원소들이 전부 자기 자신을 가리키게 초기화
  
  값이 채워지면 자기 앞 원소를 가리키게 설정
  */

  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false);
  
  int N, Ans;
  vector<int> parent;
  vector<pair<int,int>> V;
  
  void init(){
      parent.resize(1003);
      for(int i=1;i<=1001;i++){
          parent[i]=i;
      }
  }
  
  int find(int u){
      if(parent[u]==u) return u;
      return parent[u] = find(parent[u]);
  }
  
  bool compV(pair<int,int>&A, pair<int,int>&B){
      if(A.second==B.second) return A.first<B.first;
      return A.second>B.second;
  }
  
  int main(){
      fastio;
      cin>>N;
      init();
      for(int i=1;i<=N;i++){
          int a,b; cin>>a>>b;
          V.push_back({a,b});
      } sort(V.begin(),V.end(),compV);
      for(auto val : V){
          if(find(val.first)>=1){ //공간이 남아있다면
              int u = find(val.first);
              parent[u] = u-1;
              Ans += val.second; 
          }
      }
      cout<<Ans;
      return 0;
  }
  ```
  </details>

  - 마감일보다 작으면서 아직 아무것도 배정되지 않은 날에 접근할 때 Bruteforce도 가능하지만 분리집합을 사용했다.
  - 정렬하고 find로 찾아주면 끝난다.
