### [A 정보갓 영훈이 S5](https://www.acmicpc.net/problem/14843)

### [B 서든어택 3 S4](https://www.acmicpc.net/problem/22993)

### [C 촌수계산 S2](https://www.acmicpc.net/problem/2644)

### [D 삼각형으로 자르기 S2](https://www.acmicpc.net/problem/1198)

### [E INK S1](https://www.acmicpc.net/problem/30036)

### [F 잠입 G5](https://www.acmicpc.net/problem/27113)

### [G Cow on Skates G5](https://www.acmicpc.net/problem/6191)

### [H 거울 G4](https://www.acmicpc.net/problem/2344)

# 학습노트

+ 학습한 내용
  - A : 수학, 구현, 임의정밀도
  - B : 정렬, 그리디
  - C : DFS/BFS
  - D : 수학, 기하학(신발끈 공식, 헤론의 공식)
  - E : 구현, 시뮬레이션
  - F : 그리디, 많조분, 시뮬레이션
  - G : 2차원 배열에서의 BFS 경로 역추적
  - H : 구현, 시뮬레이션

+ 총평
  - 구현셋이었다.
  - 학기 말이라 시간이 많아 2일에 걸쳐서 끝냈다.
  - F번이 왜 틀렸는지 원인을 찾지 못했다.
  - 빡구현이 많아서 새롭게 배운 내용은 크게 없다.

+ ## D 삼각형으로 자르기
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //문제를 임의의 세 점을 골라 가장 큰 삼각형을 만들었을 때, 그 넓이를 구하는 문제로 치환할 수 있다.

  /*
  삼각형의 넓이를 구할 경우엔 두 가지 알고리즘을 사용할 수 있다.
  
  1. 헤론의 공식 (삼각형의 세 변을 통해 넓이를 구함)
  S = (a+b+c)/2
  A = sqrt(S*(S-a)*(S-b)*(S-c))
  
  2. 신발끈 공식 (삼각형의 세 꼭짓점의 좌표를 통해 넓이를 구함)
  x1 x2 x3 x1
  y1 y2 y3 y1
  1/2 * | x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3 |
  */
  
  #include <bits/stdc++.h>
  using namespace std;
  #define X first
  #define Y second 
  
  long double Ans = -1;
  
  int main(){
      int N; cin >> N;
      vector<pair<int, int>> V;
      while (N--) {
          int x, y; cin >> x >> y;
          V.push_back({x, y});
      }
      for (int i = 0; i < V.size() - 2; i++) {
          for (int j = i + 1; j < V.size() - 1; j++) {
              for (int k = j + 1; k < V.size(); k++) {
                  // V[i], V[j], V[k] 세 개의 점을 고른다.
                  long double x1 = V[i].X, x2 = V[j].X, x3 = V[k].X;
                  long double y1 = V[i].Y, y2 = V[j].Y, y3 = V[k].Y;
                  long double val = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
                  Ans = max(val, Ans);
              }
          }
      }
      cout << fixed << setprecision(20) << Ans;
      return 0;
  }
  ```
  </details>
  
  - 문제 단순화
  - 신발끈 공식, 헤론의 공식
 
+ ## F 잠입
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //그리디 + 많조분 + 시뮬레이션인데 너무 힘들었다.
  //레이저로 나올 수 있는 6가지 경우를 모두 생각해 코드를 제출했는데 85%에서 계속 실패해서 코드를 새로 짰다.
  
  //로봇은 레이저를 무시하고 쫓아오기에 0,0에서 Flood Fill을 하며 온다고 생각할 수 있다.
  //그렇기에 플레이어가 한 번이라도 x나 y좌표가 감소하는 방향으로 이동한다면 로봇에게 잡힌다.
  
  #include <bits/stdc++.h>
  using namespace std;
  #define ll long long
  #define st first 
  #define en second 
  
  ll N,M;
  ll Px=1; //플레이어의 x좌표
  
  int main(){
      ios::sync_with_stdio(false); cin.tie(NULL);
      cin>>N>>M;
      for(int i=0;i<N-1;i++){
          int x; cin>>x;
          char c,d; ll a,b;
          vector<pair<int,int>> V; //레이저의 시작과 끝 저장
          if(x==0) continue;
          if(x==1){
              cin>>a>>c;
              if(c=='R') V.push_back({a,M}); //Case 1
              if(c=='L') V.push_back({1,a}); //Case 2
          }
          if(x==2){
              cin>>a>>c>>b>>d;
              if(c=='R' && d=='L') V.push_back({a,b}); //Case 3
              if(c=='R' && d=='R') V.push_back({a,M}); //Case 5
              if(c=='L' && d=='L') V.push_back({1,b}); //Case 6
              if(c=='L' && d=='R'){ //Case 4
                  V.push_back({1,a});
                  V.push_back({b,M});
              }
          }
  
          if(V.size()==1){ //Case 12356
              if(Px<V[0].st || V[0].en<Px) continue; //레이저 밖의 영역으로 바로 내려가는 경우
              else if(V[0].st<=Px && Px<=V[0].en && V[0].en+1<=M) {Px=V[0].en+1; continue;} //레이저 위에 있고 오른쪽에 길이 있는 경우
              else {cout<<"NO"; return 0;} //그 밖엔 길이 없음
          }
          else if(V.size()==2){ //Case 4
              if(V[0].en<Px && Px<V[1].st) continue; //두 레이저 사이로 바로 내려가는 경우
              else if(Px<=V[0].en && V[0].en+1<V[1].st) {Px=V[0].en+1; continue;}
              else {cout<<"NO"; return 0;} //그 밖엔 길이 없음
          }
      }
      cout<<"YES";
      return 0;
  }
  ```
  </details>
  
  - 그리디 + 많은 조건 분기
  - 빡구현...

+ ## G Cows on Skates
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false);
  #define Y first 
  #define X second
  
  int N,M; //Y X
  string board[150];
  
  int dy[] = {1,0,-1,0};
  int dx[] = {0,1,0,-1};
  queue<pair<int,int>> Q;
  bool vis[150][150];
  pair<int,int> pre[150][150]; //경로복원 pre[y][x] : (y,x)로 이동하기 전에 있던 칸의 좌표
  
  int main(){
      fastio;
      cin>>N>>M;
      for(int i=0;i<N;i++) cin>>board[i];
      Q.push({0,0}); vis[0][0]=true;
      while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
  
          if(cur.Y==N-1 && cur.X==M-1){ //N,M 도착
              vector<pair<int,int>> V;
              int y=N-1,x=M-1;
              while(!(y==0 && x==0)){
                  V.push_back({y,x});
                  int ny = pre[y][x].Y;
                  int nx = pre[y][x].X;
                  y=ny, x=nx;
              }
              V.push_back({0,0});
              for(int i=V.size()-1;i>=0;i--){
                  cout<<V[i].Y+1<<' '<<V[i].X+1<<'\n';
              }
              break;
          }
  
          for(int dir=0;dir<4;dir++){
              int ny = cur.Y + dy[dir];
              int nx = cur.X + dx[dir];
              if(ny<0 || nx<0 || ny>=N || nx>=M) continue; //OOB
              if(vis[ny][nx] || board[ny][nx]=='*') continue;
              Q.push({ny,nx}); vis[ny][nx]=true;
              pre[ny][nx] = {cur.Y,cur.X};
          }
      }
      return 0;
  }
  ```
  </details>

  - BFS 경로 역추적
