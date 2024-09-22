#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

//세그트리
template <typename T>
struct SegTree{
    int N;
    vector<T> Tree;
    SegTree(int N):N(N){Tree.resize(N*4);}
    T merge(T left, T right){
        return left + right;
    }
    T update(int idx, T val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node]=val;
        ll mid = leftNode+rightNode; mid/=2;
        T leftVal = update(idx, val, node*2, leftNode, mid);
        T rightVal = update(idx, val, node*2+1, mid+1, rightNode);
        return Tree[node] = merge(leftVal, rightVal);
    }
    T query(int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return Tree[node];
        ll mid = leftNode+rightNode; mid/=2;
        T leftVal = query(left, right, node*2, leftNode, mid);
        T rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return merge(leftVal, rightVal);
    }
};

//펜윅트리
template <typename T>
struct fenwick{
    int N;
    vector<T> Tree;
    fenwick(int N):N(N){Tree.resize(N+1);}
    void update(int i, T x){
        for(;i<=N;i+=i&-i) Tree[i] += x;
    }
    T sum(int i){
        T ret = 0;
        for(;i;i-=i&-i) ret += Tree[i];
        return ret;
    }
};

//2D 펜윅트리
template <typename T>
struct fenwick2D{
    int Y, X;
    vector<vector<T>> Tree;
    fenwick2D(int Y, int X): Y(Y), X(X) {Tree.resize(Y+1, vector<T>(X+1));}
    void update(int _y, int _x, T val){
        for(int y=_y; y<=Y; y+=y&-y)
            for(int x=_x; x<=X; x+=x&-x)
                Tree[y][x] += val;
    }
    T sum(int _y, int _x){
        if(_y<=0 || _x<=0) return 0;
        T ret = 0;
        for(int y=_y; y; y-=y&-y)
            for(int x=_x; x; x-=x&-x)
                ret += Tree[y][x];
        return ret;
    }
    T query(int y1, int x1, int y2, int x2){
        return sum(y2, x2) - sum(y1-1, x2) - sum(y2, x1-1) + sum(y1-1, x1-1);
    }
};

//에라토스테네스의 채
vector<bool> isPrime(1000'010,true);
vector<int> Primes;
void seive(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=1000'003;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=1000'003;j+=i) isPrime[j]=false;
        }
    }

    for(int i=2;i<=1000'003;i++){
        if(isPrime[i]) Primes.push_back(i);
    }
}

//1차원 좌표압축 (압축된 배열 반환, 0-indexed)
vector<int> compress(vector<int>&V){
    vector<int> tmp(V);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()), tmp.end());
    for(int&val:V) val = lower_bound(tmp.begin(), tmp.end(), val) - tmp.begin();
    return V;
}

int main(){
    fastio;
    string S; cin>>S;
    int ans = 0;
    for(char c : S){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ans++;
    }
    cout<<ans;
    return 0;
}
