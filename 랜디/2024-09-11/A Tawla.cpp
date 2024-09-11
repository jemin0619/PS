#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

string solve(int a, int b){
    if(a==b){
        switch(a){
            case 1: return "Habb Yakk";
            case 2: return "Dobara";
            case 3: return "Dousa";
            case 4: return "Dorgy";
            case 5: return "Dabash";
            case 6: return "Dosh";
        }
    }
    else{
        string ret = "";
        int mx = max(a,b);
        int mn = min(a,b);

        if(mx==6 && mn==5) return "Sheesh Beesh";

        switch(mx){
            case 1: ret += "Yakk"; break;
            case 2: ret += "Doh"; break;
            case 3: ret += "Seh"; break;
            case 4: ret += "Ghar"; break;
            case 5: ret += "Bang"; break;
            case 6: ret += "Sheesh"; break;
        }
        ret += " ";
        switch(mn){
            case 1: ret += "Yakk"; break;
            case 2: ret += "Doh"; break;
            case 3: ret += "Seh"; break;
            case 4: ret += "Ghar"; break;
            case 5: ret += "Bang"; break;
            case 6: ret += "Sheesh"; break;
        }
        return ret;
    }
}

int main(){
    fastio;
    int tc; cin>>tc;
    for(int i=1; i<=tc; i++){
        int a,b; cin>>a>>b;
        cout<<"Case "<<i<<": "<<solve(a,b)<<'\n';
    }
    return 0;
}
