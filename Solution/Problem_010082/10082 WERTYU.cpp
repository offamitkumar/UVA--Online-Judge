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
    map<char,char>f;
    f['.'] = ',';
    f['\''] = ';';
    f['\\'] = ']';
    f['/'] = '.';
    f['1'] = '`';
    f[']'] = '[';
    f['2'] = '1';
    f['3'] = '2';
    f['4'] = '3';
    f['5'] = '4';
    f['6'] = '5';
    f['7'] = '6';
    f['8'] = '7';
    f['9'] = '8';
    f['0'] = '9';
    f['-'] = '0';
    f['='] = '-';
    f[';'] = 'L'; 
    f[':'] = 'L'; 
    f['D'] = 'S'; 
    f['S'] = 'A'; 
    f['F'] = 'D'; 
    f['G'] = 'F'; 
    f['H'] = 'G'; 
    f['K'] = 'J'; 
    f['L'] = 'K'; 
    f['O'] = 'I';
    f['J'] = 'H'; 
    f['['] = 'P'; 
    f['{'] = 'P'; 
    f['E'] = 'W'; 
    f['W'] = 'Q'; 

    f['R'] = 'E'; 
    f['T'] = 'R'; 
    f['Y'] = 'T'; 
    f['U'] = 'Y'; 
    f['I'] = 'U'; 
    f['O'] = 'I'; 
    f['P'] = 'O'; 
    f[','] = 'M'; 
    f['<'] = 'M'; 
    f['C'] = 'X'; 
    f['X'] = 'Z'; 
    f['V'] = 'C'; 
    f['B'] = 'V'; 
    f['N'] = 'B'; 
    f['M'] = 'N'; 
    string s;
    while(getline(cin ,s)){
        for(auto&itr:s){
            if(f.find(itr)!=f.end()){
                cout << f[itr];
            }else{
                cout << itr;
            }
        }
        cout << '\n'; 
    }
    return 0;
}
