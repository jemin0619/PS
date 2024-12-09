//세그 풀이도 직관적이지 못함...
//그냥 레이지 풀이로 가기로 했습니다
//두 개의 레이지 배열을 사용해서, 하나는 앞면으로 돌리는 flag, 하나는 뒤집는 flag로 놓습니다.
//앞면으로 돌리는 경우엔 해당 노드의 앞면으로 돌리는 flag를 1로, 뒤집는 flag는 모두 0으로 초기화합니다.
//prop 함수도 제대로 동작할 수 있게 짜주면 AC를 받습니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll MX = 200'000;

ll seg[MX*4], lazy_f[MX*4], lazy_s[MX*4];

void prop(int node, int leftNode, int rightNode){
    if(!lazy_f[node] && !lazy_s[node]) return;
    if(leftNode!=rightNode){
        if(lazy_s[node]){
            lazy_s[node*2] = lazy_s[node*2+1] = 1;
            lazy_f[node*2] = lazy_f[node*2+1] = 0;
        }
        lazy_f[node*2] += lazy_f[node];
        lazy_f[node*2+1] += lazy_f[node];
    }
    if(lazy_s[node]) seg[node] = 0;
    seg[node] += lazy_f[node];
    lazy_f[node] = lazy_s[node] = 0;
    return;
}

void update(int left, int right, int val, int node, int leftNode, int rightNode){
    prop(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return;
    if(left<=leftNode && rightNode<=right){
        if(val>0) lazy_f[node] += val;
        else {lazy_f[node]=0; lazy_s[node]=1;}
        prop(node, leftNode, rightNode);
        return;
    }
    int mid = leftNode+rightNode; mid/=2;
    update(left, right, val, node*2, leftNode, mid);
    update(left, right, val, node*2+1, mid+1, rightNode);
}

int query(int idx, int node, int leftNode, int rightNode){
    prop(node, leftNode, rightNode);
    if(leftNode==rightNode) return seg[node];
    int mid = leftNode+rightNode; mid/=2;
    if(mid>=idx) return query(idx, node*2, leftNode, mid);
    else return query(idx, node*2+1, mid+1, rightNode);
}

int main(){
    fastio;
    int N; cin>>N;
    for(int i=0; i<N; i++){
        int x; cin>>x;
        int state = query(x, 1, 1, N);
        if(state%2) cout<<"0 ";
        else{
            cout<<x<<' ';
            update(1, x-1, 1, 1, 1, N);
            update(x+1, N, -1, 1, 1, N);
        }
    }
    return 0;
}
