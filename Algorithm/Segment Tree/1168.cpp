#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, K;
vector<int> SegTree;

int merge(int left, int right){
    return left + right;
}

int init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return SegTree[node]=1;
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

int Kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        SegTree[node] = SegTree[node]-1;
        return leftNode;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    int Val = K<=SegTree[node*2]?Kth(K,node*2,leftNode,mid):Kth(K-SegTree[node*2],node*2+1,mid+1,rightNode);
    SegTree[node] = merge(SegTree[node*2],SegTree[node*2+1]);
    return Val;
}

int main(){
    fastio;
    cin>>N>>K;
    SegTree.resize((N+1)*4);
    init(1,1,N);
    cout<<"<";
    int X = 1;
    while(SegTree[1]>0){
        if(SegTree[1]!=N) cout<<", ";
        X  = ((X-2)+K)%SegTree[1]+1;
        cout<<Kth(X,1,1,N);
    }   
    cout<<">";
    return 0;
}

/*
K = 3

1 2 3 4 5 6 7

1. Seg[1]=7 | 3번째로 작은 수 
2. Seg[1]=6 | 5번째로 작은 수 
3. Seg[1]=5 | 2번째로 작은 수 
4. Seg[1]=4 | 4번재로 작은 수 
5. Seg[1]=3 | 3번째로 작은 수 
6. Seg[1]=2 | 1번째로 작은 수 
7. Seg[1]=1 | 1번째로 작은 수 

X가 0에 도달하면 안되므로 잘 신경써서 식을 세워야 한다.
*/
