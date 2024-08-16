// 1 ~ 100'0000
// Query 1: K번째 수를 구하고 -1
// Query 2: A B가 주어지면 맛 A인 사탕을 B만큼 넣음 (음수면 뺌)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
const int MX = 100'0001;

vector<int> SegTree(MX*4);

int merge(int left, int right){
    return left + right;
}

int update(int idx, int newValue, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return SegTree[node];
    if(leftNode == rightNode) return SegTree[node]+=newValue; //더해줌
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = update(idx, newValue, node*2, leftNode, mid);
    int rightVal = update(idx, newValue, node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

int Kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        SegTree[node]-=1;
        return leftNode;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    int Val = K<=SegTree[node*2]?Kth(K,node*2,leftNode,mid):Kth(K-SegTree[node*2],node*2+1,mid+1,rightNode);
    SegTree[node] = merge(SegTree[node*2], SegTree[node*2+1]);
    return Val;
}

int main(){
    fastio;
    int N; cin>>N;
    while(N--){
        int A,B,C; cin>>A;
        if(A==1){
            cin>>B;
            cout<<Kth(B,1,1,MX)<<'\n';
        }
        if(A==2){
            cin>>B>>C;
            update(B,C,1,1,MX);
        }
    }
    return 0;
}
