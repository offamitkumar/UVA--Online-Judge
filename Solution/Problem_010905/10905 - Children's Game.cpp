#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool compare(string&a, string&b){
    return (a+b) > (b+a);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n;
    while(cin >>n , n){
        vector<string>v(n);
        for(auto&itr:v){
            cin>>itr;
        }
        sort(v.begin(), v.end() , compare);
        for(auto&itr:v){
            cout<<itr;
        }
        cout<<'\n';
    }
    return 0;
}
