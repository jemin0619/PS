### [학습자료](https://blog.naver.com/jinhan814/222607789392)

# 이분 탐색 (Binary Search)
- 결정 문제에서 답이 이분적일 때 사용할 수 있는 탐색기법
- 경계를 포함하는 구간 [lo, hi]를 잡은 뒤 구간의 길이를 절반씩 줄여가며 [lo, hi]가 경계에 위치하도록 하는 아이디어를 사용
- 시간복잡도는 check(mid)의 시간복잡도가 O(T)일 때 O(T*log(n))

## [BOJ 2805 나무 자르기](https://www.acmicpc.net/problem/2805)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

vector<ll> V;
ll N, M;

bool Check(ll x){
    ll sum = 0;
    for(int v : V){
        if(v > x) sum += (v-x);
    }
    return sum >= M;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        V.push_back(x);
    }

    ll lo = 0, hi = 1e9;
    while(lo+1 < hi){
        ll mid = (hi+lo)/2;
        if(Check(mid)) lo = mid;
        else hi = mid;
    }
    cout<<lo;
    return 0;
}
```
</details>

## [BOJ 2792 보석 상자](https://www.acmicpc.net/problem/2792)
<details>
<summary> 접기/펼치기 </summary>

```cpp
//모든 보석을 나눠줘야 하고, 한 사람은 같은 색의 보석만 가져갈 수 있음
//Check(Mid) : 한 사람이 가져갈 수 있는 최대 보석 개수(질투심)를 Mid개로 정할 수 있는가?
//FT로 존재하므로 hi를 출력한다. (질투심 제한을 늘릴수록 모든 보석을 사람들에게 나눠줄 수 있음 (못받는사람도 존재) , M<=N)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,M; //사람수 보석수
vector<ll> V;

bool Check(ll x){ 
    ll num = 0; //나누어진 보석 묶음의 개수
    for(ll val : V){
        num += (val/x + (val%x!=0));
    }
    //보석 묶음의 개수가 사람들 수보다 작거나 같으면 모든 보석을 나눠줄 수 있다.
    return num<=N;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        ll x; cin>>x;
        V.push_back(x);
    }
    
    ll lo=0, hi=1e9;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
    return 0;
}
```
</details>

+ lo, hi 범위 구하기
    - 처음 풀 때 lo를 1로 해서 틀렸었다.
    - lo와 hi를 잡을 땐 파라미터가 FFTT로 존재한다면 Check(lo)=F Check(hi)=T로, TTFF라면 반대로 잡아야 한다.
    - lo가 1이면 3 3 1 1 1 같은 TC에선 1로도 모든 보석을 나눠줄 수 있기에 TTTT가 되어서 잘못된 답을 출력한다.

## [BOJ 3079 입국심사](https://www.acmicpc.net/problem/3079)
<details>
<summary> 접기/펼치기 </summary>

```cpp
//hi는 10^18로 잡는다. 
//심사에 10^9 시간이 걸리는 심사대에 10^9명이 심사를 받을 경우
//Max_M(=10^9) * Max_T(=10^9) = 10^18

//Check(mid) : mid 시간 내로 모든 사람(M명)이 입국심사를 마칠 수 있는가?

//N     1 ~ 10^5
//M     1 ~ 10^9
//Tx    1 ~ 10^9

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,M;
vector<ll> T;

bool Check(ll x){
    ll cnt = 0;
    for(ll val : T){
        cnt += (x/val);
        if(cnt>=M) return true; //오버플로가 발생할 수 있기에 반환을 미리 해준다.
    }
    return false;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        T.push_back(x);
    }
    
    ll lo=0 ,hi=1e18;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
    return 0;
}
```
+ OVF 주의하기 (중요)
</details>

- 오버플로 발생 방지 테크닉

## [BOJ 2110 공유기 설치](https://www.acmicpc.net/problem/2110)
<details>
<summary> 접기/펼치기 </summary>

```cpp
//Check(mid) 두 공유기 사이의 최소 거리가 mid가 되게 공유기를 C개 이상 배치할 수 있는가?
//C개 이상 배치할 수 있어야하는 이유는 C개를 설치하고 남은 개수는 설치되지 않아도 가장 인접한 두 공유기 사이 거리가 mid로 유지됨
//TTFF로 구성되므로 lo를 출력

//idx를 구할 때 범위가 V.begin()+idx ~ 이므로 무한 루프에 빠지지 않는다.
//lo가 0인 경우는 존재하지 않아 1로 했고, hi는 V의 최댓값이 10^9이므로 그보다 하나 큰 10^9 +1로 해서 Check(hi)=F가 항상 성립하게 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,C;
vector<ll> V;

bool Check(ll x){
    ll cnt=0, idx=0;
    while(idx<N){
        idx = lower_bound(V.begin()+idx, V.end(), V[idx]+x) - V.begin();
        cnt++;
    }
    return cnt >= C;
}

int main(){
    fastio;
    cin>>N>>C;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        V.push_back(x);
    }
    sort(V.begin(),V.end());

    ll lo=1, hi=1e9+1;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) lo=mid;
        else hi=mid;
    }
    cout<<lo;
    return 0;
}
```
</details>

- Check에서의 이분탐색 사용 아이디어

## [BOJ 1477 휴게소 세우기](https://www.acmicpc.net/problem/1477)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

int N,M,L;
vector<int> V;

//FFTT로 존재, hi를 출력

bool Check(ll x){ //휴게소가 없는 구간 최댓값이 x가 되도록 M개의 휴게소를 지을 수 있는가?
    int cnt = 0;
    for(int i=1;i<V.size();i++){
        //알고리즘을 이렇게 짜면 0과 L에는 자연스럽게 휴게소 설치가 되지 않는다.
        cnt += (V[i]-V[i-1]-1)/x;
    }
    return cnt <= M; //필요한 휴게소 개수가 M보다 작거나 같으면 성립합. M보다 많으면 지을 수 없음
}

int main(){
    fastio;
    cin>>N>>M>>L;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    }
    V.push_back(0); 
    V.push_back(L);
    sort(V.begin(),V.end());

    int lo=0, hi=L;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
```
</details>

## [BOJ 16434 드래곤 앤 던전](https://www.acmicpc.net/problem/16434)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//Chk는 FFTT로 존재함
//Chk(0)=F (항상)
//Chk(1.23456e17+1) = T(항상)

//100만 * 100만 * 123456 = 1.23456e17
//대략 큰 값인 1e18 + 7로 잡아도 된다.

//1번 쿼리를 반복문으로 처리할 경우 시간초과가 무조건 발생하기에 수학적으로 처리해야 한다.
//몬스터의 체력을 Hm, 공격력을 Atkm, 용사의 체력을 Hh, 공격력을 Atkh로 정의한다.
//용사가 몬스터를 죽이려면 ceil(Hm/Atkh) 번 공격해야 한다. (ceil은 반올림)
//이를 풀어서 쓰면 다음과 같다. ceil(Hm/Atkh) = (Hm+Atkh-1)/Atkh
//용사가 선공이기에 몬스터는 용사보다 한 번 적게 공격한다.
//그러므로 (Hm+Atkh-1)/Atkh -1 번의 공격을 Atkm의 공격력으로 시전한다는 것이다.
//즉 ((Hm+Atkh-1)/Atkh -1)*Atkm이 용사가 받는 데미지라고 할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N, Hatk;
vector<tuple<ll,ll,ll>> V;

bool Check(ll x){ //최대체력 x로 드래곤을 쓰러뜨릴 수 있는가
    ll Health=x; ll Atk=Hatk; 
    for(auto[t,a,h] : V){
        if(t==1){ //공격력 a, 체력 h인 몬스터와 조우
            Health -= ((h+Atk-1)/Atk-1)*a;
            if(Health<=0) return false;
        }
        if(t==2){ //공격력 + a, 체력 + h
            Atk += a;
            Health = min(x,Health+h);
        }
    }
    return true;
}  

int main(){
    fastio;
    cin>>N>>Hatk;
    for(int i=0;i<N;i++){
        ll t,a,h; cin>>t>>a>>h;
        V.push_back({t,a,h});
    }
    ll lo=0, hi=1e18+7;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
```
</details>

- 구현 / 매개변수탐색
- ceil 없는 반올림 아이디어


## [BOJ 1300 K번째 수](https://www.acmicpc.net/problem/1300)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//2차원 배열을 만들고 정렬하는 풀이는 시간복잡도, 메모리 제한상 불가능하다.
//다음과 같은 관찰을 통해 시간복잡도를 획기적으로 줄일 수 있다.

// 1 2 3
// 2 4 6
// 3 6 9

//다음의 N=3, N*N 배열에서 6보다 작거나 같은 수를 구하려면 어떻게 해야 할까?
//각 행의 첫 번째 항을 a라고 정의한다.
//이때 첫 번째 행에서 6보다 작거나 같은 수의 개수는 min(6/a,N)이고, 모든 행을 살핀 값을 더하면 다음과 같다.
//min(6/1, N) + min(6/2, N) + min(6/3, N)

//각 행마다 a ~ a*N 의 수만 존재하기에 어떤 수 X보다 작거나 같은 수의 개수를 구하러면 min(X/a, N)을 때리면 된다.

//파라미터가 FFTT로 존재하도록 Check(0)=F, Check(10^9)=T 로 잡았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,K;

bool Check(ll x){  //A[i][j] <= X를 만족하는 A[i][j]의 개수가 K보다 크거나 같은가?
    ll cnt = 0;
    for(int i=1;i<=N;i++){
        cnt += min<ll>(x/i, N);
    }
    return cnt >= K;
}

int main(){
    fastio;
    cin>>N>>K;
    ll lo=0, hi=1e9;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
```
</details>

- 수학적 통찰력을 이용한 최적화


## [BOJ 2512 예산](https://www.acmicpc.net/problem/2512)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//Check(x) 지방당 최대예산이 x일때 총 예산이 M을 넘는가?
//파라미터가 FFTT로 존재하는 결정문제
//lo를 출력.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

int N,M;
vector<int> V;

bool Check(int x){ //지방당 최대예산이 x일때 총 예산이 M을 넘는가?
    int sum = 0;
    for(int val : V){
        sum += min(val, x);
    }
    return sum > M;
}

int main(){
    fastio;
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    } cin>>M;

    int lo=-1, hi=*max_element(V.begin(),V.end())+1;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<lo;
    return 0;
}
```
</details>

- lo와 hi의 초기값은 파라미터(mid)가 도달할 수 없는 범위이다.
- mid는 범위를 줄여나가는 것이므로 lo+1, hi-1에까지만 도달할 수 있다.


## [BOJ 2022 사다리](https://www.acmicpc.net/problem/2022)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//x와 y를 빗변으로 하는 직각삼각형의 높이를 h1, h2라고 할때, 삼각형 닮음을 사용해 다음과 같은 공식을 유도할 수 있습니다.
//c = (h1*h2) / (h1+h2)
//h1 = sqrt(x^2 - w^2)
//h2 = sqrt(y^2 - w^2)

//삼각형의 성질에 의해 w는 min(x,y) 보다 작습니다.
//mid를 움직이며 c에 가장 근접한 c보다 작거나 같은 해를 찾고 출력합니다.
//TTFF로 존재하므로 T(lo)를 출력합니다.
//오차범위를 10^(-4)로 해서 hi를 출력해도 상관없을 것 같기는 합니다.
//실제로 상관이 없고, 같은 이치로 Check의 return 조건도 같다 기호를 생략해도 됩니다.
//실수오차가 존재하는 문제에서는 항상 좀 더 널널하게 잡아주는게 유리한 것 같습니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ld long double

ld x,y,c;

bool Check(ld mid){ // mid는 w를 의미
    ld h1 = sqrt(x*x - mid*mid);
    ld h2 = sqrt(y*y - mid*mid);
    ld val_c = (h1*h2) / (h1+h2); // w==mid 일때의 c를 구함
    return c >= val_c; 
}

int main(){
    fastio;
    cin>>x>>y>>c;
    ld lo=0, hi=min(x,y);
    while(lo+1e-4<hi){
        ld mid = (lo+hi)/2;
        if(Check(mid)) hi = mid; //T면 경계를 <- 
        else lo = mid; //F면 경계를 ->
    }
    cout<<fixed<<setprecision(4)<<hi;
    return 0;
}
```
</details>

- 기하학 문제에서의 이분탐색
- 이분탐색에서의 실수오차 활용
- 수학적 사고력


## [BOJ 13397 구간 나누기 2](https://www.acmicpc.net/problem/13397)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//숫자 하나만으로도 구간을 구성할 수 있으므로 M만 충분하다면 모든 문제의 답은 0이 될 수 있다.
//문제와 해설을 이해하는데 상당한 시간이 걸렸던 문제이다...

#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> V;

bool check(int mid){ //배열을 M개 이하의 구간으로 나누어, [가장 큰 구간 점수의 최댓값-최소값] 이 mid보다 작거나 같게 되도록 만들 수 있는가?
    int cnt = 1;
    int Mx = 0, Mn = 10001;
    for(int i=0;i<N;i++){
        Mx = max(Mx, V[i]);
        Mn = min(Mn, V[i]);

        //V[i]가 포함됨으로 인해 [가장 큰 구간 점수의 최댓값-최소값]이 mid를 넘어섰다면 V[i]를 포함시키기 전으로 돌아가서 배열을 자른다.
        //그래야 [가장 큰 구간 점수의 최댓값-최솟값]이 mid를 넘지 않게 유지할 수 있다.
        if(Mx - Mn > mid){
            cnt++; 
            Mx=V[i], Mn=V[i];
        }
    }
    return cnt<=M;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    }
    
    //Check(-1)은 항상 False이고, Check(1e9)는 아마 항상 True일 것이다.
    //그러므로 -1 ~ 1e9-1 을 돌게 구성했다.

    int lo=-2, hi=1e9;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
    return 0;
}
```
</details>

- 문제 꼼꼼히 읽기 (M 이하의 구간으로 나눌 수 있음)
- 문제 단순화
