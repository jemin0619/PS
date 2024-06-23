### [A 와이버스 부릉부릉 B5](https://www.acmicpc.net/problem/14645)

### [B Switching Lights B1](https://www.acmicpc.net/problem/6069)

### [C DNA S4](https://www.acmicpc.net/problem/1969)

### [D 골드바흐 파티션 S2](https://www.acmicpc.net/problem/17103)

### [E Large PhD Restaurant S2](https://www.acmicpc.net/problem/14012)

### [F Bee Problem G5](https://www.acmicpc.net/problem/16294)

### [G 검문 G4](https://www.acmicpc.net/problem/2981)

### [H 게임 G4](https://www.acmicpc.net/problem/28423)

# 학습노트

+ 학습한 내용
  - A : 구현
  - B : 구현
  - C : 그리디, 문자열
  - D : 수학, 에라토스테네스의 채
  - E : 그리디
  - F : 벌집 모양에서의 BFS
  - G : 수학, 유클리드 호제법
  - H : DFS

+ ## C DNA
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false);
  
  int N,M;
  vector<string> V;
  pair<string,int> ans={"",0};
  
  int main(){
      fastio;
      cin>>N>>M;
      for(int i=0;i<N;i++){
          string X; cin>>X;
          V.push_back(X);
      }
      for(int i=0;i<M;i++){ //자리별로 탐색
          int a[4]={0,}; //A C G T 순
          for(int j=0;j<N;j++){
              if(V[j][i]=='A') a[0]++;
              if(V[j][i]=='C') a[1]++;
              if(V[j][i]=='G') a[2]++;
              if(V[j][i]=='T') a[3]++;
          }
          //cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<'\n';
          int mxidx=0;
          for(int i=1;i<4;i++){
              if(a[i] > a[mxidx]){
                  mxidx = i;
              } 
          }
          if(mxidx==0) ans.first += 'A';
          if(mxidx==1) ans.first += 'C';
          if(mxidx==2) ans.first += 'G';
          if(mxidx==3) ans.first += 'T';
          ans.second += (N-a[mxidx]);
      }
      cout<<ans.first<<'\n'<<ans.second;
      return 0;
  }
  ```
  </details>
  
  - sol1) BruteForce -> TLE
  - sol2) Greedy -> AC
  - 모든 경우의 DNA를 생성하는 것은 시간초과에 걸리므로 Greedy하게 각 자리마다 가장 많이 나온 문자를 고른다.
 
+ ## D 골드바흐 파티션
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL) -> sync_with_stdio(false);
  
  vector<bool> isPrime(1000'010,true);
  vector<int> Primes;
  
  void seive(){
      isPrime[0] = isPrime[1] = false;
      for(int i=2;i*i<=1000'003;i++){
          if(isPrime[i]){
              for(int j=i*i;j<=1000'003;j+=i) isPrime[j]=false;
          }
      }
      for(int i=2;i<=1000'003;i++){
          if(isPrime[i]) Primes.push_back(i);
      }
  }
  
  int main(){
      fastio;
      seive();
      int t; cin>>t;
      while(t--){
          int n; cin>>n;
          int ans = 0;
          for(int val : Primes){
              if(val>n) break;
              if(val*2==n) continue;
              if(isPrime[n-val]) ans++; //쌍이 지어지는 경우만 체크
          }
          ans/=2; //겹치는 쌍들을 없앰
          if(isPrime[n/2]) ans++;
          cout<<ans<<'\n';
      }
      return 0;
  }
  ```
  </details>
  
  - seive로 빠르게 소수 구하기

+ ## F Bee Problem
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false);
  #define ll long long
  
  ll K,N,M;
  char board[1003][1003];
  bool vis[1003][1003];
  vector<ll> V;
  ll dy[6] = {0,1,1,0,-1,-1};
  ll dx[2][6] = {{-1,-1,0,1,0,-1},{-1,0,1,1,1,0}};
  
  int main(){
      fastio;
      cin>>K>>N>>M;
  
      if(K==0) {cout<<0; return 0;}
  
      for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
              cin>>board[i][j];
          }
      }
  
      for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
              if(vis[i][j]) continue;
              if(board[i][j]=='#') continue;
              
              ll sz=1;
              queue<pair<ll,ll>> Q;
              Q.push({i,j}); vis[i][j]=true;
  
              while(!Q.empty()){
                  auto cur = Q.front(); Q.pop();
                  for(int dir=0;dir<6;dir++){
                      ll ny = cur.first + dy[dir];
                      ll nx = cur.second + dx[cur.first%2][dir];
                      if(ny<0 || nx<0 || ny>=N || nx>=M) continue; //OOB
                      if(vis[ny][nx]) continue;
                      if(board[ny][nx]=='#') continue;
                      Q.push({ny,nx}); vis[ny][nx]=true;
                      sz++;
                  }
              }
              V.push_back(sz);
          }
      }
      sort(V.begin(),V.end(),greater<>());
      partial_sum(V.begin(),V.end(),V.begin());
  
      //K보다 작은가
      //TTFF -> F 출력
      ll lo=-1, hi=V.size();
      while(lo+1<hi){
          ll mid = (lo+hi)/2;
          if(V[mid]<K) lo=mid;
          else hi=mid;
      }
      if(hi>=V.size()) cout<<V.size();
      else cout<<hi+1;
  
      return 0;
  }
  ```
  </details>
  <img width="551" alt="image" src="https://github.com/jemin0619/PS/assets/72261100/37810f0b-db1a-4768-9941-bbd5ec851e4f">

  - 벌집 모양에서의 BFS 생각하기 (row가 짝/홀에 따라 다름)
  - 이분탐색을 통한 빠른 해 구하기 (선형탐색도 가능함)

 
 + ## G 검문
    <details>
    <summary> 접기/펼치기 </summary>
  
    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    #define fastio cin.tie(NULL) -> sync_with_stdio(false);
    
    int N;
    vector<int> V;
    vector<int> ans;
    
    int main(){
        fastio;
        cin>>N;
        for(int i=0;i<N;i++){
            int x; cin>>x;
            V.push_back(x);
        }
        sort(V.begin(),V.end());
    
        int M = V[1]-V[0];
        
        for(int i=2;i<N;i++)
            M = __gcd(M,V[i]-V[i-1]);
    
        for(int i=1;i*i<=M;i++){ //M의 모든 약수를 구함
            if(M%i==0){
                ans.push_back(i);
                if(i != M/i) ans.push_back(M/i);
            }
        }
        sort(ans.begin(),ans.end());
        for(int val : ans){ //M은 1보다 커야 하므로 1을 제외하고 출력한다.
            if(val==1) continue;
            cout<<val<<' ';
        }
        return 0;
    }
    ```
    </details>
  
    - A = aM + r
    - B = bM + r
    - C = cM + r
    - B-A = (b-a)M
    - C-B = (c-b)M
    - 만족하는 모든 M을 구해야 하므로 M은 B-A와 C-B의 최대공약수이다.
    - M을 유클리드 호제법으로 구한 다음 1을 제외한 M의 약수를 출력한다.

+ ## H 게임
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false);
  #define ll long long
  
  ll L, R, ans;
  map<string,bool> vis;
  map<string,int> dp;
  
  string f(string str){
      ll mul=1, sum=0;
      for(char c : str){
          mul *= (c-'0');
          sum += (c-'0');
      }
      string ret = to_string(sum)+to_string(mul);
      return ret;
  }
  
  int DFS(string str){
      if(vis[str]) return dp[str];
      vis[str]=true;
      string ret = f(str);
      if(stoll(ret)>100000) return dp[str] = -1;
      if(ret==str) return dp[str] = 1;
      return dp[str] = DFS(ret);
  }
  
  int main(){
      fastio;
      cin>>L>>R;
      for(int i=L;i<=R;i++){
          ans += DFS(to_string(i));
      }
      cout<<ans;
      return 0;
  }
  ```
  </details>
  
    - 전형적인 DFS문제.
    - 10만을 넘기면 -1로 처리한다는 부분을 보지 못해서 틀렸었다.
    - 1~10만까지 시뮬레이션을 돌려보니 배열 크기를 50만정도로 잡으면 굳이 Map을 안써도 될 것 같았는데, 안전빵으로 썼다.
