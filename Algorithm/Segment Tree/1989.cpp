//Segment Tree로 range minimun query, range sum query를 처리
//range minimun query로 1~N에서 최소값을 구하고 sum(1,N) * rmq(1,N)을 ans로 갱신
//rmq로 구한 전체 최솟값을 mid라고 했을 때, 1~mid-1과 mid+1~N 두 구역으로 나눠서 생각할 수 있음
//두 구간에서도 이와 같은 방식으로 ans를 갱신한다면 답을 구할 수 있을 것 같다는 생각이 들었음

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tlll tuple<ll,ll,ll> //sum min maxidx
#define fastio cin.tie(NULL)->sync_with_stdio(false)
const ll MX = 101'0101;

int N;
ll Ans = -1;
ll Ans_st;
ll Ans_en;
vector<tlll> SegTree;
vector<ll> V;

tlll merge(tlll left, tlll right){
    auto&[l_sum, l_min, l_idx] = left;
    auto&[r_sum, r_min, r_idx] = right;
    return {l_sum+r_sum, min(l_min, r_min), V[l_idx]>V[r_idx]?r_idx:l_idx};
}

tlll init(int node, int leftNode ,int rightNode){
    if(leftNode==rightNode) return SegTree[node] = {V[leftNode], V[leftNode], leftNode};
    ll mid = leftNode + (rightNode-leftNode)/2;
    tlll leftVal = init(node*2, leftNode, mid);
    tlll rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

tlll query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return {0,MX,0};
    if(left<=leftNode && rightNode<=right) return SegTree[node];
    ll mid = leftNode + (rightNode-leftNode)/2;
    tlll leftVal = query(left, right, node*2, leftNode, mid);
    tlll rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

void solve(int st, int en){
    if(st>en) return;
    auto[sum, mn, mid] = query(st,en,1,1,N);
    if(Ans < sum*mn){
        Ans = sum*mn;
        Ans_st = st;
        Ans_en = en;
    }
    solve(st, mid-1);
    solve(mid+1, en);
}

int main(){
    fastio;
    cin>>N;
    V.resize(N+1); V[0]=MX;
    for(int i=1;i<=N;i++) cin>>V[i];
    SegTree.resize(N*4); init(1,1,N);
    solve(1,N);
    cout<<Ans<<'\n'<<Ans_st<<' '<<Ans_en;
    return 0;
}
