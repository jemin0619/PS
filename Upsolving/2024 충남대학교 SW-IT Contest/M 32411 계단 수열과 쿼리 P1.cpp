//https://github.com/GONGRYONGWANG/ProblemSolving/blob/752253058d15ee31c98066d675eb33cb37d8a5af/%EB%B0%B1%EC%A4%80/Platinum/32411.%E2%80%85%EA%B3%84%EB%8B%A8%E2%80%85%EC%88%98%EC%97%B4%EA%B3%BC%E2%80%85%EC%BF%BC%EB%A6%AC/%EA%B3%84%EB%8B%A8%E2%80%85%EC%88%98%EC%97%B4%EA%B3%BC%E2%80%85%EC%BF%BC%EB%A6%AC.cc
//구조체 세그에 Lazy Prop이 붙으니 난이도가 확 올랐다...
//처음엔 태그에 Lazy가 없어서 없이 되나 했는데, 필요했다.

//sorohue님 코드 보면 lazy 없이 하셨던데 보법이 다른듯 하네요..

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const int MX = 101010;

struct Node{
    int sz=0, left, right;
    vector<int> dp_left, dp_right, dp_mx;
    Node(){}
    Node(int val){
        sz = 1;
        left = right = val;
        dp_left.resize(11, 1);
        dp_right.resize(11, 1);
        dp_mx.resize(11, 1);
    }
};

Node merge(Node L, Node R){ 
    if(L.sz==0) return R;
    if(R.sz==0) return L;
    Node ret(1);
    ret.sz = L.sz + R.sz;
    ret.left = L.left;
    ret.right = R.right;
    int diff = abs(L.right - R.left);
    for(int i=1; i<=10; i++){
        ret.dp_left[i] = L.dp_left[i];
        if(L.sz==L.dp_left[i] && diff==i) ret.dp_left[i] += R.dp_left[i];

        ret.dp_right[i] = R.dp_right[i];
        if(R.sz==R.dp_right[i] && diff==i) ret.dp_right[i] += L.dp_right[i];

        ret.dp_mx[i] = max({ret.dp_left[i], ret.dp_right[i], L.dp_mx[i], R.dp_mx[i]});
        if(diff==i) ret.dp_mx[i] = max(ret.dp_mx[i], L.dp_right[i]+R.dp_left[i]);
    }
    return ret;
}

Node seg[MX*4];
int V[MX];
int lazy[MX*4];

void init(int node, int leftNode, int rightNode){
    lazy[node] = 0;
    if(leftNode==rightNode) {seg[node] = Node(V[leftNode]); return;}
    int mid = leftNode+rightNode; mid/=2;
    init(node*2, leftNode, mid);
    init(node*2+1, mid+1, rightNode);
    seg[node] = merge(seg[node*2], seg[node*2+1]);
}

void prop(int node, int leftNode, int rightNode){
    if(lazy[node]!=0){
        if(leftNode!=rightNode){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        seg[node].left += lazy[node];
        seg[node].right += lazy[node];
        lazy[node] = 0;
    }
}

void update(int left, int right, int val, int node, int leftNode, int rightNode){
    prop(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return;
    if(left<=leftNode && rightNode<=right){
        lazy[node] += val;
        prop(node, leftNode, rightNode);
        return;
    }
    int mid = leftNode+rightNode; mid/=2;
    update(left, right, val, node*2, leftNode, mid);
    update(left, right, val, node*2+1, mid+1, rightNode);
    seg[node] = merge(seg[node*2], seg[node*2+1]);
}

Node query(int left, int right, int node, int leftNode, int rightNode){
    prop(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return Node();
    if(left<=leftNode && rightNode<=right) return seg[node];
    int mid = leftNode+rightNode; mid/=2;
    Node leftVal = query(left, right, node*2, leftNode, mid);
    Node rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    int N, Q; cin>>N>>Q;
    for(int i=1; i<=N; i++) cin>>V[i];
    init(1, 1, N);
    while(Q--){
        int q,i,j,k; cin>>q>>i>>j>>k;
        if(q==1) update(i, j, k, 1, 1, N);
        else cout<<query(i, j, 1, 1, N).dp_mx[k]<<'\n';
    }
    return 0;
}
