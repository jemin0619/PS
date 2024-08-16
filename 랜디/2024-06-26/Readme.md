### [A Beehives B2](https://www.acmicpc.net/problem/24767)

### [B 사탕 S4](https://www.acmicpc.net/problem/1812)

### [C 가장 가까운 세 사람의 심리적 거리 S1](https://www.acmicpc.net/problem/20529)

### [D 혼자 하는 윷놀이 S1](https://www.acmicpc.net/problem/24467)

### [E 토너먼트 승자 S2](https://www.acmicpc.net/problem/1404)

### [F 맥주 마시면서 걸어가기 G5](https://www.acmicpc.net/problem/9205)

### [G 복권 + 은행 G5](https://www.acmicpc.net/problem/13258)

### [H K번째 음식 찾기 G3](https://www.acmicpc.net/problem/23792)

# 학습노트

+ 학습한 내용
  - A : 구현
  - B : 수학, 구현
  - C : 비둘기집 원리 
  - D : 구현, 시뮬레이션, 많조분
  - E : 확률론, 수학
  - F : 그래프에서의 BFS
  - G : 확률론, 수학, 기댓값 DP
  - H : 이분탐색, 매개변수탐색

+ 총평
  - 굉장히 어려웠다.
  - A와 D 빼면 전부 타 블로그의 도움을 받았다...
  - 수학, 비둘기집원리, 기댓값DP 등 너무 약한 부분만 출제된 셋이라 힘들었던 것 같다.

+ ## B 사탕
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //수학적 관찰력이 필요했음
  //N이 홀수이므로 문제를 해결할 수 있다. (처음에 짝수도 되는줄 알고 어떻게 풀지 고민함)
  //V[0] = a0+a1 
  //V[1] = a1+a2 
  //V[2] = a2+a3 
  //V[3] = a3+a4 
  //V[4] = a4+a0
  //이때 a1을 구하려면 V[0]+V[1]을 시행해 2a1+a0+a2를 만든다.
  //그 후 남은 수들을 V[2]부터 - + - + - .. 순으로 연산을 해나가면 2a1만 남게 되고, 절반 값을 답으로 취할 수 있다.
  //핵심은 오른쪽으로 이동하면서 모든 수를 연산에 사용하고, 오른쪽에 수가 존재하지 않으면 0번째 인덱스로 이동해서 모든 수를 사용할때까지 반복하는 것이다.
  
  //a0을 구하는 경우엔 범위 처리가 달라져서 따로 뺐다.
  
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false);
  
  int N;
  vector<int> V;
  vector<int> Ans;
  
  int main(){
      cin>>N;
      for(int i=0;i<N;i++){
          int x; cin>>x;
          V.push_back(x);
      }
  
      int i1 = N-1; int i2 = 0;
      int val = V[i1] + V[i2];
      bool minus = true;
      for(int i=i2+1;i<=i1-1;i++){
          if(minus) val -= V[i];
          else val += V[i];
          minus = !minus;    
      }
      val/=2;
      Ans.push_back(val);
  
      for(int i2=1;i2<N;i2++){
          int i1 = i2-1;
          int val = V[i1] + V[i2];
          bool minus = true;
          for(int i=i2+1;i<N;i++){
              if(minus) val -= V[i];
              else val += V[i];
              minus = !minus;
          }
          for(int i=0;i<=i1-1;i++){
              if(minus) val -= V[i];
              else val += V[i];
              minus = !minus;
          }
          val/=2;
          Ans.push_back(val);
      }
      for(int val : Ans) cout<<val<<'\n';
      return 0;
  }
  ```
  </details>
  
  - 규칙 찾기
 
+ ## C 가장 가까운 세 사람의 심리적 거리
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //비둘기집 원리를 알아야 함
  //100개의 비둘기 집이 있을 때 비둘기 101마리가 집에 들어갔다면 한 집에는 두 비둘기가 들어가 있다는 것을 알 수 있다.
  //이처럼 MBTI도 16개뿐이기에 N이 32보다 크다면 같은 MBTI 3개가 존재한다는 것을 알 수 있다.
  //그렇기에 N이 32보다 작거나 같으면 브루트포스로 답을 구하고 아니면 0을 출력한다.
  
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)
  #define ll long long
  
  ll diff(string A, string B){
      ll ret = 0;
      for(int i=0;i<4;i++){
          if(A[i]!=B[i]) ret++;
      }
      return ret;
  }
  
  int main(){
      ll t; cin>>t;
      while(t--){
          ll N; cin>>N;
          vector<string> V;
          for(int i=0;i<N;i++){
              string x; cin>>x;
              V.push_back(x);
          }
          if(N>33) {cout<<"0\n"; continue;}
          
          ll mn = 0x7f7f7f7f;
          for(int i=0;i<N;i++){
              for(int j=0;j<N;j++){
                  for(int k=0;k<N;k++){
                      if(i==j || j==k || k==i) continue;
                      ll val = diff(V[i],V[j]) + diff(V[j],V[k]) + diff(V[k],V[i]);
                      mn = min(val, mn);
                  }
              }
          }
          cout<<mn<<'\n';
      }
      return 0;
  }
  ```
  </details>
  
  - 비둘기집 원리 + 시뮬레이션

+ ## E 토너먼트 승자
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //확률론 문제인데 KOI 느낌이 났음.

  #include <bits/stdc++.h>
  using namespace std;
  
  double arr[10][10];
  double A[10]; //i번 선수가 4강전에 올라올 확률
  double B[10];
  double C[10];
  
  //01 02 03 04 05 06 07
  //XX 12 13 14 15 16 17
  //XX XX 23 24 25 26 27
  //XX XX XX 34 35 36 37
  //XX XX XX XX 45 46 47
  //XX XX XX XX XX 56 57
  //XX XX XX XX XX XX 67
  
  //1라운드
  // 0 VS 1
  // 2 VS 3
  // 4 VS 5
  // 6 VS 7
  
  //2라운드
  // (0 vs 1) VS (2 vs 3)
  // (4 vs 5) VS (6 vs 7)
  
  //3라운드
  // ((0 vs 1) vs (2 vs 3)) VS ((4 vs 5) vs (6 vs 7))
  
  int main(){
      for(int i=0;i<=6;i++){
          for(int j=i+1;j<=7;j++){
              double x; cin>>x;
              arr[i][j] = x/100;
              arr[j][i] = 1 - arr[i][j];
          }
      }
  
      A[0] = arr[0][1];
      A[1] = arr[1][0];
      A[2] = arr[2][3];
      A[3] = arr[3][2];
      A[4] = arr[4][5];
      A[5] = arr[5][4];
      A[6] = arr[6][7];
      A[7] = arr[7][6];
  
      B[0] = A[0]*(A[2]*arr[0][2] + A[3]*arr[0][3]); //0이 2라에 올라왔고  * (상대로 2가 올라와서 이겼거나 + 상대로 3이 올라와서 이겼거나)
      B[1] = A[1]*(A[2]*arr[1][2] + A[3]*arr[1][3]); //1이 2라에 올라왔고  * (상대로 2가 올라와서 이겼거나 + 상대로 3이 올라와서 이겼거나)
      B[2] = A[2]*(A[0]*arr[2][0] + A[1]*arr[2][1]);
      B[3] = A[3]*(A[0]*arr[3][0] + A[1]*arr[3][1]);
      B[4] = A[4]*(A[6]*arr[4][6] + A[7]*arr[4][7]);
      B[5] = A[5]*(A[6]*arr[5][6] + A[7]*arr[5][7]);
      B[6] = A[6]*(A[4]*arr[6][4] + A[5]*arr[6][5]);
      B[7] = A[7]*(A[4]*arr[7][4] + A[5]*arr[7][5]);
  
      C[0] = B[0]*(B[4]*arr[0][4] + B[5]*arr[0][5] + B[6]*arr[0][6] + B[7]*arr[0][7]);
      C[1] = B[1]*(B[4]*arr[1][4] + B[5]*arr[1][5] + B[6]*arr[1][6] + B[7]*arr[1][7]);
      C[2] = B[2]*(B[4]*arr[2][4] + B[5]*arr[2][5] + B[6]*arr[2][6] + B[7]*arr[2][7]);
      C[3] = B[3]*(B[4]*arr[3][4] + B[5]*arr[3][5] + B[6]*arr[3][6] + B[7]*arr[3][7]);
      C[4] = B[4]*(B[0]*arr[4][0] + B[1]*arr[4][1] + B[2]*arr[4][2] + B[3]*arr[4][3]);
      C[5] = B[5]*(B[0]*arr[5][0] + B[1]*arr[5][1] + B[2]*arr[5][2] + B[3]*arr[5][3]);
      C[6] = B[6]*(B[0]*arr[6][0] + B[1]*arr[6][1] + B[2]*arr[6][2] + B[3]*arr[6][3]);
      C[7] = B[7]*(B[0]*arr[7][0] + B[1]*arr[7][1] + B[2]*arr[7][2] + B[3]*arr[7][3]);
  
      for(int i=0;i<8;i++){
          printf("%.25f ",C[i]);
      }
      return 0;
  }
  ```
  </details>

  - 수학, 확률론, 구현

 
 + ## F 맥주 마시면서 걸어가기
    <details>
    <summary> 접기/펼치기 </summary>
  
    ```cpp
    //그래프에서의 BFS로 해결 가능
    //맥주를 마시면서 걸으면 최대 1000의 거리까지 이동이 가능하므로 현재 위치부터 다음 곳까지의 거리가 1000보다 작거나 같으면 이동할 수 있다.
    
    #include <bits/stdc++.h>
    using namespace std;
    #define fastio cin.tie(NULL)->sync_with_stdio(false);
    #define pii pair<int,int>
    #define X first
    #define Y second
    
    int main(){
        fastio;
        int t; cin>>t;
        while(t--){
            int n; cin>>n;
            pii home, des;
            vector<pii> store;
            vector<bool> vis(n);
            cin>>home.X>>home.Y;
            for(int i=0;i<n;i++){
                int sx, sy; cin>>sx>>sy;
                store.push_back({sx,sy});
            }
            cin>>des.X>>des.Y;
    
            bool flag = false;
            queue<pii> Q;
            Q.push({home.X,home.Y});
            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();
                if(abs(cur.X-des.X)+abs(cur.Y-des.Y)<=1000) {flag=true; break;}
                for(int i=0;i<n;i++){
                    if(vis[i]) continue;
                    if(abs(cur.X-store[i].X)+abs(cur.Y-store[i].Y)<=1000){
                        vis[i] = true;
                        Q.push({store[i].X,store[i].Y});
                    }
                }
            }
            if(flag) cout<<"happy\n";
            else cout<<"sad\n";
        }
        return 0;
    }
    ```
    </details>
  
    - 그래프에서의 BFS
    - 문제 단순화 (1000의 거리를 한번에 갈 수 있고, 도중에 편의점 있으면 또 1000의 거리 이동 가능)

+ ## G 복권 + 은행
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //태그가 DP + Math인데 굳이 DP를 사용하지 않아도 된다.
  //DP[i]를 i주의 기댓값으로 정의하고, Ans를 DP로 대체하면 DP 풀이로 해결할 수 있다.
  
  //기댓값 DP라는 표현이 있어서 찾아보니 해당 블로그를 발견했다
  //https://newdeal123.tistory.com/31
  //여길 참고해 공부하는게 좋을 것 같다.
  
  #include <bits/stdc++.h>
  using namespace std;
  
  double Ans = 0.0;
  double N,J,C;
  double Tickets;
  vector<double> V;
  
  int main(){
      cin>>N;
      for(int i=0;i<N;i++){
          double x; cin>>x;
          V.push_back(x);
          Tickets += x;
      }
      cin>>J>>C;
      Ans = V[0];
      for(int i=0;i<C;i++){
          Ans += J*Ans/Tickets;
          Tickets += J;
      }
      printf("%.10f",Ans);
      return 0;
  }
  ```
  </details>
  
    - 기댓값 DP
    - 수학, 확률론, DP(안써도됨)
 
  + ## H K번째 음식 찾기 2
  <details>
  <summary> 접기/펼치기 </summary>

  ```cpp
  //https://pill27211.tistory.com/115
  //위 글에서 도움을 받았다.
  
  //Parametric Search + Binary Search 문제이다.
  //Func(vector<int>&V, X) : 배열 V에서 X번째 요소가 답이 될 수 있는가?
  
  //추가로 쿼리에서의 입력은 1-indexed이므로 범위 설정에 주의한다.
  //Func == true인 상황은 {X + V이외의 배열에서 V[X]보다 작은 원소의 개수}가 K인 경우이다.
  //이때 X는 0-indexed이고 K은 1-indexed이므로 X+1을 해주었다.
  
  //Binary Search가 끝난 이후의 lo엔 cnt<=K 일 때의 인덱스가 들어가 있으므로 X에 lo를 대입했을 때 true인지 확인한다.
  //true라면 type과 lo+1을 출력하고 false라면 V를 다른 배열로 바꿔서 탐색을 시작한다.
  
  #include <bits/stdc++.h>
  using namespace std;
  #define fastio cin.tie(NULL)->sync_with_stdio(false)
  
  int N,Q;
  vector<int> V[3];
  
  bool solve(vector<int>&X, vector<int>&Y, vector<int>&Z, int type, int k, int x, int y, int z){
      int lo = -1, hi = x;
      while(lo+1<hi){
          int mid = (lo+hi)/2;
          int cnt = mid+1;
          cnt += lower_bound(Y.begin(),Y.begin()+y,X[mid]) - Y.begin();
          cnt += lower_bound(Z.begin(),Z.begin()+z,X[mid]) - Z.begin();
          if(cnt>k) hi = mid;
          else lo = mid;
      }
  
      bool flag = (k == lo+1+lower_bound(Y.begin(),Y.begin()+y,X[lo])-Y.begin()+lower_bound(Z.begin(),Z.begin()+z,X[lo])-Z.begin()); 
  
      if(flag){
          cout<<type<<' '<<lo+1<<'\n';
          return true;
      }
  
      return false;
  }
  
  int main(){
      fastio;
      cin>>N;
  
      for(int i=0;i<3;i++){
          for(int j=0;j<N;j++){
              int x; cin>>x;
              V[i].push_back(x);
          }
      }
  
      cin>>Q;
      while(Q--){
          int x,y,z,k; cin>>x>>y>>z>>k;
          if(solve(V[0],V[1],V[2],1,k,x,y,z));
          else if(solve(V[1],V[0],V[2],2,k,y,x,z));
          else solve(V[2],V[0],V[1],3,k,z,x,y);
      }
      return 0;
  }
  ```
  </details>
  
    - 매개변수탐색을 여러 번 돌리는 테크닉
    - 수학적 관찰력 (BOJ 1300 K번째 수)
