//정해는 이분 그래프 판별이라고 한다.
//2-SAT로 XOR 연산을 그래프에 적용시켜서 풀 수 있다. (둘 중 하나에만 로봇이 들어가야함)
//XOR은 A'B or AB'으로 나타낼 수 있는데, or도 분배법칙을 적용시킬 수 있으므로
//(A' or A) and (A' or B') and (B or A) and (B or B')로 나타낼 수 있고,
//항등식을 없애주면 (A' or B') and (A or B)로 나타낼 수 있다.

//그러므로 교차하는 선분들에 대해 다음 4개의 간선을 추가해주면 된다.
//A -> B'
//B -> A'
//A' -> B
//B' -> A

//교차를 판별할 때 수로원이 겹치는 것은 교차한다고 보면 안된다.
//TC 2에서 그 이유를 알 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

#pragma region
struct Point{
    int x, y;
    bool operator <= (Point const & P){
        if(x==P.x) return y <= P.y;
        return x <= P.x;
    }
    bool operator == (Point const & P){
        return P.x==x && P.y==y;
    }
};

struct Line{
    Point p1, p2;
};

int CCW(Point a, Point b, Point c){
    ll T1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll T2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(T1-T2>0) return 1;
    else if(T1-T2==0) return 0;
    else return -1;
}

bool cross(Line a, Line b){
    int D1 = CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2);
    int D2 = CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2);
    if(D1<=0 && D2<=0){
        if(D1==0 && D2==0){
            if(a.p2 <= a.p1) swap(a.p1, a.p2);
            if(b.p2 <= b.p1) swap(b.p1, b.p2);
            return a.p1<=b.p2 && b.p1<=a.p2;
        }
        return true;
    }
    return false;
}
#pragma endregion

int W,P; //수원지개수, 파이프개수

vector<vector<int>> adj;
vector<int> order;
vector<int> SccNum;
stack<int> stk;

//1~P       : true
//P+1 ~ 2P  : false
int oppose(int num){
    if(num>P) return num-P;
    return num+P;
}

int orderCnt = 0;
int sccCnt = 0;
int SCC(int cur){
    stk.push(cur);
    int ret = order[cur] = orderCnt++;
    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt));
        else if(SccNum[nxt]==-1) ret = min(ret, order[nxt]);
    }
    if(ret == order[cur]){
        while(true){
            int x = stk.top(); stk.pop();
            SccNum[x] = sccCnt;
            if(x==cur) break; 
        }
        sccCnt++;
    }
    return ret;
}

int main(){
    fastio;
    cin>>W>>P;
    vector<Point> V(W+1);
    vector<Line> L(P+1);
    adj.resize(2*P+3);
    order.resize(2*P+3, -1);
    SccNum.resize(2*P+3, -1);
    for(int i=1; i<=W; i++) cin>>V[i].x>>V[i].y;
    for(int i=1; i<=P; i++){
        int s,x,y; cin>>s>>x>>y;
        L[i].p1.x = x; 
        L[i].p1.y = y;
        L[i].p2 = V[s];
    }
    for(int i=1; i<=P; i++){
        for(int j=i+1; j<=P; j++){
            //L[i]와 L[j]가 교차하면서 수로원이 달라야됨 
            //수로원이 같은 것을 교차한다고 받아들이면 안됨
            if(cross(L[i], L[j]) && !(L[i].p2==L[j].p2)){
                //두 Line 중 하나엔 로봇이 다녀야 하므로 XOR을 떠올릴 수 있다.
                //(not u or not v) and (u or v)
                int u = i; int v = j;
                adj[u].push_back(oppose(v));
                adj[v].push_back(oppose(u));
                adj[oppose(u)].push_back(v);
                adj[oppose(v)].push_back(u);
            }
        }
    }
    for(int i=1; i<=2*P; i++){
        if(order[i]==-1) SCC(i);
    }
    for(int i=1; i<=P; i++){
        if(SccNum[i]==SccNum[i+P]){
            cout<<"impossible";
            return 0;
        }
    }
    cout<<"possible";
    return 0;
}
