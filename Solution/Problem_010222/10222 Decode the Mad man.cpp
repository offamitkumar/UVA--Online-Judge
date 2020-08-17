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
    map<char , char> f; 
    f[';'] = 'k'; 
    f[':'] = 'k'; 
    f['\''] = 'l'; 
    f['"'] = 'l'; 
    f['d'] = 'a'; 
    f['f'] = 's'; 
    f['g'] = 'd'; 
    f['h'] = 'f'; 
    f['k'] = 'h'; 
    f['l'] = 'j'; 
    f['o'] = 'u';
    f['j'] = 'g'; 
    f['['] = 'o'; 
    f['{'] = 'o'; 
    f[']'] = 'p'; 
    f['}'] = 'p'; 
    f['e'] = 'q'; 
    f['r'] = 'w'; 
    f['t'] = 'e'; 
    f['y'] = 'r'; 
    f['u'] = 't'; 
    f['i'] = 'y'; 
    f['o'] = 'u'; 
    f['p'] = 'i'; 
    f[','] = 'n'; 
    f['<'] = 'n'; 
    f['>'] = 'm'; 
    f['.'] = 'm'; 
    f['c'] = 'z'; 
    f['v'] = 'x'; 
    f['b'] = 'c'; 
    f['n'] = 'v'; 
    f['m'] = 'b'; 
    string s; 
    while(getline(cin , s)) {
        cin.ignore();
        for(auto &itr: s){
            if(isspace(itr)){
                cout << itr;
            }else{
                if(isalpha(itr)){
                    itr =char(tolower(itr));
                }
                cout << f[itr];
            }
        }
        cout << '\n'; 
   }
    return 0;
}
