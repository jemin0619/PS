//S3 문제인데 P3마냥 풀었다.
//요세푸스 문제였는데, 마지막으로 지운 자리 +1에서 시작해서 다시 지우기 시작하므로 range sum을 써줘야 했다.
//31865번 문제랑 같은 풀이이다.

//덱을 사용한 풀이가 있는 것 같은데...

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> Tree;

int update(int idx, int val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Tree[node];
    if(leftNode==rightNode) return Tree[node]=val;
    int mid = (leftNode+rightNode)/2;
    int leftVal = update(idx, val, node*2, leftNode, mid);
    int rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Tree[node] = leftVal + rightVal;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return Tree[node];
    int mid = (leftNode+rightNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightVal;
}

int Kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        Tree[node]=0;
        return leftNode;
    }
    int mid = (leftNode+rightNode)/2;
    int Val = K<=Tree[node*2]?Kth(K,node*2,leftNode,mid):Kth(K-Tree[node*2],node*2+1,mid+1,rightNode);
    Tree[node] = Tree[node*2] + Tree[node*2+1];
    return Val;
}

int main(){
    fastio;
    ll N; cin>>N;
    Tree.resize((N+1)*4);
    for(int i=1; i<=N; i++){
        update(i, 1, 1, 1, N);
    }
    ll T = 1;
    ll pre = 0;
    while(Tree[1]!=1){ //수가 하나 남을 때까지
        ll MOD = Tree[1];
        ll R = (query(1, pre, 1, 1, N) + (T % MOD * T % MOD * T % MOD)) % MOD;
        if(R==0) R = MOD;
        pre = Kth(R, 1, 1, N);
        T++;
    }
    cout<<Kth(1, 1, 1, N);
    return 0;
}
