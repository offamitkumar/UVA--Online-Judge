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
    int n; cin >> n;
    cin.ignore();
    while(n--){
        string s; getline(cin , s);
        bool possible = true;
        stack<char>st;
        for(auto&itr:s){
            if(itr == '{'){
                st.push('}');
            }else if(itr == '('){
                st.push(')');
            }else if(itr == '['){
                st.push(']');
            }else if(st.empty() || st.top() != itr){
                possible = false;
                break;
            }else{
                st.pop();
            }
        }
        if((!possible) || st.size()){
            cout <<"No";
        }else{
            cout <<"Yes";
        }
        cout << '\n'; 
    }
    return 0;
}
