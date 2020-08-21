#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s; 
    while(cin >> s && s != "0"){
        cout << s ;
        int res = 0;
        for(auto&itr:s){
            res *= 10; 
            res += (itr -'0');
            res%=11;
        }
        if(!res){
            cout <<" is a multiple of 11.";
        }else{
            cout <<" is not a multiple of 11.";
        }
        cout << '\n'; 
    }
    return 0;
}
