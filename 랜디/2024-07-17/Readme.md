### [A Backward numbers B3](https://www.acmicpc.net/problem/6721)

### [B Casino S4](https://www.acmicpc.net/problem/9351)

### [C In Danger S3](https://www.acmicpc.net/problem/6537)

### [D Parse the Syntax Tree S2](https://www.acmicpc.net/problem/26450)

### [E Competition S1](https://www.acmicpc.net/problem/22256)

### [F 팰린드롬과 관련된 수열의 개수 G5](https://www.acmicpc.net/problem/17360)

### [G 인경강 G4](https://www.acmicpc.net/problem/25712)

### [H Quick out of the Harbour G3](https://www.acmicpc.net/problem/5382)

# 학습노트

+ 학습한 내용
  - A : 구현, 문자열
  - B : 문자열, 브루트포스 or DP(팰린드롬)
  - C : 수학, 요세푸스 f(N,2)
  - D : 트리, DFS
  - E : 정렬, 그리디
  - F : 수학, 많조분
  - G : 구현
  - H : 다익스트라

+ 총평
  - 팰린드롬만 두 문제가 나왔는데, B번 Casino는 너무 힘들었다.
  - 누구는 매내쳐를 쓰고, DP를 쓰고... Bruteforce 풀이는 뭔지 모르겠다.
  - 전에 풀었던 팰린드롬? 문제에서 DP[st][en]이 팰린드롬인지 묻는 쿼리 부분을 가져와서 해결했다.
  - E는 정렬 방식이 특이해서 기억에 남는다. A[i]-B[i] 기준으로 정렬하면, B가 높을수록 앞에, A가 높을수록 뒤에 위치하게 된다.
  - F는 PS보다는 수학 문제에 가까운 듯 하다.
  - G는 구현이 재밌었다.
  - H는 다익스트라였는데 다시 복습하고 풀 수 있었다.

+ ## B Casino
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  
  int d[1003][1003]; // [Start idx][End idx] 가 팰린드롬 수인가?
  
  void Palindrome(string a, int len) {
      memset(d, 0, sizeof(d)); // 배열 초기화
      for (int i = 0; i < len; i++) {
          d[i][i] = 1; // 길이가 1이면 모두 팰린드롬 수
          if (i + 1 < len && a[i] == a[i + 1]) d[i][i + 1] = 1; // 같은 수가 연속으로 온 경우 체크
      }
  
      for (int gap = 2; gap < len; gap++) {
          for (int i = 0; i + gap < len; i++) {
              int s = i, e = i + gap;
              // 시작과 끝이 같고, 그 전 단계가 팰린드롬 수면 팰린드롬 수이다
              if (a[s] == a[e] && d[s + 1][e - 1]) d[s][e] = 1;
          }
      }
  }
  
  vector<string> solve(string S) {
      vector<string> ans;
      int len = S.size();
      Palindrome(S, len);
  
      int mxSize = 0;
      for (int st = len - 1; st >= 0; st--) {
          for (int en = len - 1; en >= st; en--) {
              if (d[st][en]) {
                  int currentLength = en - st + 1;
                  if (currentLength > 1) { // 길이가 1인 회문 제외
                      if (currentLength > mxSize) {
                          mxSize = currentLength;
                          ans.clear();
                          ans.push_back(S.substr(st, currentLength));
                      } else if (currentLength == mxSize) {
                          ans.push_back(S.substr(st, currentLength));
                      }
                  }
              }
          }
      }
  
      return ans;
  }
  
  int main() {
      int t; cin >> t;
      for (int i = 1; i <= t; i++) {
          string s; cin >> s;
          vector<string> ans = solve(s);
          cout << "Case #" << i << ":\n";
          for (string val : ans) cout << val << '\n';
      }
      return 0;
  }

  ```
  </details>
  - 문자열 뒤쪽에 존재하는 회문부터 출력해야 하는걸 잊어선 안된다.
 
+ ## D Parse the Syntax Tree
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define ll long long
  
  int H, W, idx=1;
  vector<string> Tree;
  
  ll solve(int y, int x){
      if('0'<=Tree[y][x] && Tree[y][x]<='9') return (ll)(Tree[y][x]-'0');
      int right, left;
      for(int nx=x-1;nx>=0;nx--)
          if(Tree[y+1][nx]!='.')
              {left = nx; break;}
      for(int nx=x+1;nx<Tree[y].size();nx++)
          if(Tree[y+1][nx]!='.')
              {right = nx; break;}
      if(Tree[y][x]=='+') return solve(y+1,left)+solve(y+1,right);
      if(Tree[y][x]=='-') return solve(y+1,left)-solve(y+1,right);
      if(Tree[y][x]=='*') return solve(y+1,left)*solve(y+1,right);
  }
  
  int main(){
      cin>>H>>W;
      for(int i=0;i<H;i++){
          string x; cin>>x;
          Tree.push_back(x);
      }
      for(int i=0;i<Tree[0].size();i++){
          if(Tree[0][i]!='.'){
              cout<<solve(0,i);
              break;
          }
      }
      return 0;
  }
  ```
  </details>
  
  - 트리의 성질을 활용해 for문으로 자식을 찾을 수 있다.
  - N이 작아 충분히 가능한 전략이다.

+ ## E Competition
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  
  int main(){
      ios::sync_with_stdio(false); cin.tie(0);
      int N,a,b; cin>>N>>a>>b;
      vector<int> A(N), B(N);
      vector<pair<int,int>> V;
      for(int i=0;i<N;i++) cin>>A[i];
      for(int i=0;i<N;i++) cin>>B[i];
      for(int i=0;i<N;i++) V.push_back({A[i]-B[i], i});
      sort(V.begin(), V.end());
      //앞에서부터 b명은 B 그룹, 나머지는 A 그룹에 넣을 수 있다.
      //V에서 앞에 있을수록 B 과목을 상대적으로 잘 본 사람이라는 것이고, 뒤에 있을수록 A 과목을 상대적으로 잘 본 사람이라는 의미.
      int ans = 0;
      for(int i=0;i<N;i++){
          if(i<b) ans += B[V[i].second];
          else ans += A[V[i].second];
      }
      cout<<ans;
      return 0;
  }
  ```
  </details>

  - A[i]-B[i] 혹은 B[i]-A[i] 순으로 정렬하는 테크닉
  - a+b=N이기에 가능했는데 a+b<N이면 어떻게 해야 할까
 
+ ## G 인경강
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  #define ff first
  #define ss second
  
  int main(){
      fastio;
      int N, M; cin>>N>>M;
      vector<int> V(M);
      for(int i=0;i<M;i++) cin>>V[i];
      vector<pair<int,int>> pre;
      for(int i=0;i<M;i++){
          V[i]/=2;
          vector<pair<int,int>> cur;
          vector<pair<int,int>> live; //살아있는(이동가능한) 부분들
          while(V[i]--){
              int st, en; cin>>st>>en;
              cur.push_back({st,en});
          }
          if(pre.empty()) pre=cur;
          else{
              for(auto c : cur){
                  for(auto p : pre){
                      if((p.ff<=c.ff && c.ff<=p.ss) || (p.ff<=c.ss && c.ss<=p.ss) || (c.ff<=p.ff && p.ff<=c.ss) || (c.ff<=p.ss && p.ss<=c.ss)) {
                          live.push_back(c);
                          break;
                      }
                  }
              }
              if(live.empty()) {cout<<"NO"; return 0;}
              pre.clear();
              for(auto val : live){
                  pre.push_back(val);
              }
          }
      }
      cout<<"YES";
      return 0;
  }
  ```
  </details>

  - 이전 부분과 비교해서 이동가능한 곳만 살리면 해결할 수 있다.
  - 처음엔 live를 set으로 만들어서 원소가 중복되지 않게 했는데, 애초에 원소가 중복되지 않게 코드를 짜면 set을 쓰지 않아도 된다.
 
+ ## H Quick out of the Harbour 
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define tiii tuple<int,int,int>
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  
  const int INF = 1e9 + 10;
  int dy[] = {0,1,0,-1};
  int dx[] = {1,0,-1,0};
  
  int main(){
      fastio;
      int t; cin>>t;
      while(t--){
          int N, M, C; //세로 가로 @여는데걸리는시간
          priority_queue<tiii,vector<tiii>,greater<tiii>> PQ;
          cin>>N>>M>>C; 
          vector<vector<char>> board(N,vector<char>(M));
          vector<vector<int>> d(N, vector<int>(M, INF));
          for(int i=0;i<N;i++){
              for(int j=0;j<M;j++){
                  cin>>board[i][j];
                  if(board[i][j]=='S'){
                      d[i][j] = 0;
                      PQ.push({d[i][j],i,j});
                  }
              }
          }
          while(!PQ.empty()){
              auto [curW, curY, curX] = PQ.top();
              PQ.pop();
  
               //맵 밖으로 나가면 종료
              if(curY==0 || curY==N-1 || curX==0 || curX==M-1){
                  cout<<d[curY][curX]+1<<'\n';
                  break;
              }
  
              for(int dir=0;dir<4;dir++){
                  int ny = curY+dy[dir];
                  int nx = curX+dx[dir];
                  if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                  if(board[ny][nx]=='#') continue;
  
                  //@면 1+C만큼 기다려야하고, 아니면 이동에 1만큼 걸린다.
                  int nw = (board[ny][nx]=='@' ? 1+C : 1);
                  if(d[ny][nx]<=d[curY][curX]+nw) continue;
                  d[ny][nx]=d[curY][curX]+nw;
                  PQ.push({d[ny][nx],ny,nx});
              }
          }
      }
      return 0;
  }
  ```
  </details>

  - 다익스트라
  - @면 @까지 한 칸 이동하고 C턴동안 쉬어야 하므로 1+C로 놓을 수 있다.
  - vis를 놓으면 속도 면에서 최적화가 되는지 모르겠는데 없더라도 길이 비교하는 부분에서 짤려서 괜찮다.
