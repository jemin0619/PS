### [A КУРИЕРИ B3](https://www.acmicpc.net/problem/24302)

### [B 旅人 S3](https://www.acmicpc.net/problem/5560)

### [C 달나라 토끼를 위한 구매대금 지불 도우미 S3](https://www.acmicpc.net/problem/17212)

### [D 3의 제곱 S3](https://www.acmicpc.net/problem/4312)

### [E Left and Right S3](https://www.acmicpc.net/problem/16630)

### [F 피자 굽기 G5](https://www.acmicpc.net/problem/1756)

### [G 로봇조립 G4](https://www.acmicpc.net/problem/18116)

### [H 사전 순 최대 공통 부분 수열 G4](https://www.acmicpc.net/problem/30805)

# 학습노트

+ 학습한 내용
  - A : 구현 (뭔가 문제가 애매함)
  - B : 누적합
  - C : DP
  - D : 비트마스킹, 수학, 큰 수 연산
  - E : 그리디
  - F : 모노톤 스택
  - G : 유니온 파인드
  - H : 그리디

+ ## C 달나라 토끼를 위한 구매대금 지불 도우미
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  
  #define fastio cin.tie(NULL) -> sync_with_stdio(false);
  #define ll long long
  
  const ll INF = 0x7f7f7f7f;
  ll n;
  ll dp[5][100003]; // i번째 동전까지 고려했을 때 j를 만들어내는 동전의 최소개수
  ll coin[5] = {0, 1, 2, 5, 7}; // 동전의 값들
  
  int main() {
      fastio;
      cin>>n;
    
      for(int i=0; i<=4; i++)
          for(int j=0; j<=n; j++)
              dp[i][j] = INF;
    
      dp[0][0] = 0;
    
      for (int i=1; i<=4; i++) {
          for (int j=0; j<=n; j++) {
              dp[i][j] = dp[i-1][j];
              if(j-coin[i]>=0) dp[i][j] = min(dp[i][j], dp[i][j-coin[i]]+1);
          }
      }
      cout<<dp[4][n];
      return 0;
  }
  ```
  </details>
  
  - sol1) knapsack DP
  - sol2) 1차원 DP
  - 동전이 주어지지 않으면 Knapsack 풀이가 유일하다.
  - 동전이 주어졌으므로 DP 테이블 초기값 세팅이 가능하고, 1차원 DP로 해결할 수 있다.
  - [BOJ 1473 1로 만들기](https://www.acmicpc.net/problem/1463)
  - 위 문제를 풀듯이 해결할 수 있다.

+ ## D 3의 제곱
  <details>
  <summary> 접기/펼치기 </summary>

  ```py
  import sys

  while(True):
      n = int(input())
      if(n==0): break
      n -= 1
      bin = list(format(n, 'b'))
      bin.reverse()
      ans = []
      for i in range(len(bin)):
          if(bin[i]=='0'): continue
          ans.append(3**int(i))
      if(len(ans)==0): print("{ }")
      else:
          result = "{ " + ", ".join(map(str,ans)) + " }"
          print(result)
  ```
  </details>
  
  - 나만모르는웰노운같음
  - 패턴 파악 -> 비트마스킹 떠올리기
  - Python의 Big Integer 활용

+ ## E Left and Right
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false);

  int N,idx;
  string S;
  vector<int> ans;
  stack<pair<char,int>> St;
  
  int main(){
      fastio;
      cin>>N>>S;
      S = "R"+S;
      ans.resize(N+1);
      for(int i=0;i<N;i++){
          if(S[i]=='R'){
              while(!St.empty()){
                  auto cur = St.top(); St.pop();
                  ans[cur.second] = ++idx;
              }
          }
          St.push({S[i],i});
      }
      while(!St.empty()){
          auto cur = St.top(); St.pop();
          ans[cur.second] = ++idx;
      }
      for(int i=0;i<N;i++){
          cout<<ans[i]<<'\n';
      }
      return 0;
  }
  ```
  </details>
  
  - 풀이를 듣고 나면 어렵지 않은데 혼자 떠올리기가 어려워서 해설을 확인함
  - 가상의 시작점 0을 설정하면 모든 동작 앞에 R을 붙여서 생각할 수 있다.
  - 문자열에서 L들의 묶음을 Ls라고 할 때, 문자열을 R와 R+Ls로 나눌 수 있다(R+Ls로 묶을 수 있다면 묶어야 함)
  - 시작점을 0으로 설정하고, R이라면 이전 위치+1을, R+Ls라면 뒤에서부터 이전 위치+1을 매긴다.
  - 사전순으로 가장 빠른 답을 출력해야하기에 최적으로 필요한 만큼만 딱딱 이동해야 한다.
  - 그렇기에 이 풀이가 성립한다.
 
+ ## H 사전 순 최대 공통 부분 수열
  <details>
  <summary> 접기/펼치기 </summary>
    
  ```cpp
  #include <bits/stdc++.h>
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  using namespace std;
  
  vector<int> A, B, ans;
  int Aidx, Bidx;
  
  int main() {
      fastio;
      int n, m;
      cin>>n;
      for(int i=0;i<n;i++){
          int x; cin>>x;
          A.push_back(x);
      }
      cin>>m;
      for(int i=0;i<m;i++){
          int x; cin>>x;
          B.push_back(x);
      }

    while(Aidx<n && Bidx<m){
        vector<int> Achk(101,-1);
        vector<int> Bchk(101,-1);
        for(int i=Aidx;i<n;i++){
            if(Achk[A[i]]==-1) Achk[A[i]]=i;
        }
        for(int i=Bidx;i<m;i++){
            if(Bchk[B[i]]==-1) Bchk[B[i]]=i;
        }
        bool found = false;
        for(int i=100;i>=1;i--){
            if(Achk[i]==-1 || Bchk[i]==-1) continue;
            ans.push_back(i);
            Aidx = Achk[i]+1;
            Bidx = Bchk[i]+1;
            found = true;
            break;
        }
        if(!found) break;
    }

    cout<<ans.size()<<'\n';
    for(int val : ans) cout<<val<<' ';
    return 0;
  }
  ```
  </details>
  
  - 마찬가지로 풀이를 듣고 나면 어렵지 않은데 생각해내기가 어려웠다.
  - N, M, A[i], B[i] 모두 1 <= x <= 100이라 시간복잡도에 얽매이지 않고 풀이를 작성할 수 있다.
  - 일단 A, B 모두 idx=0에서 시작합니다.
  - 수열을 돌면서 각 수열에 있는 각 숫자가 최초로 등장하는 idx를 배열에 저장합니다. (1~100 사이라 가능함)
  - 100 ~ 1 까지 for문을 순회하며 A와 B에서 그 숫자가 모두 등장했다면 그 숫자를 ans에 push합니다.
  - 그 후 Aidx와 Bidx를 갱신하고 순회를 종료하고, 이 작업을 반복합니다.
  - 이를 (Aidx < N && Bidx < M) 일때까지 반복하고, ans에 push할 숫자가 없었다면 작업을 종료하고 출력을 시작합니다.
