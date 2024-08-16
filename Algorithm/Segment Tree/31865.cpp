//Kth Query

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int N;
vector<int> SegTree;
vector<int> Pos; //Pos[x]: 수 x의 위치
vector<int> Ans; //Ans[x]: x번 자리에 있는 수

int merge(int left, int right){
    return left + right;
}

int init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return SegTree[node]=1;
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(SegTree[node*2], SegTree[node*2+1]);
}

int Kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        SegTree[node]=0;
        return leftNode;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    int Val = K<=SegTree[node*2]?Kth(K,node*2,leftNode,mid):Kth(K-SegTree[node*2],node*2+1,mid+1,rightNode);
    SegTree[node] = merge(SegTree[node*2], SegTree[node*2+1]);
    return Val;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return SegTree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N;

    SegTree.resize((N+1)*4);
    Pos.resize(N+1);
    Ans.resize(N+1);
    init(1,1,N);
    Kth(1,1,1,N); //수 1은 1번 자리에 미리 놓음
    Pos[1] = 1; //수 1의 위치는 1
    Ans[1] = 1; //1번 자리엔 수 1이 놓여져있음

    for(int i=2;i<=N;i++){
        int P,X; cin>>P>>X;
        int K = (query(1,Pos[P],1,1,N)+X)%SegTree[1];
        if(K==0) K=SegTree[1];
        int Kth_num = Kth(K,1,1,N);
        Pos[i] = Kth_num;
        Ans[Kth_num] = i;
    }

    for(int i=1;i<=N;i++) cout<<Ans[i]<<'\n';
    return 0;
}
