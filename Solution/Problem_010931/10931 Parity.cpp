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
    int n;
    while(cin >> n, n){
        int one_counter{}; 
        stack<int>s; 
        while(n){
            s.push(n%2);
            one_counter+=(s.top()==1);
            n/=2;
        }
        cout <<"The parity of "; 
        while(!s.empty()){
            cout << s.top();
            s.pop();
        }
        cout <<" is " << one_counter <<" (mod 2).\n";
    }
    return 0;
}
