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
    while(getline(cin ,s)){
        istringstream ss(s);
        char ch;
        while(ss >> ch){
            int x{};
            while(ch>='0' && ch <= '9'){
                x+=(ch-'0');
                ss >> ch;
            }
            if(ch == 'b'){
                cout << string(x,' ');
            }else if(ch != '!'){
                cout << string(x,ch);
            }else{
                cout << '\n'; 
            }
        }
        cout << '\n'; 
    }
    return 0;
}
