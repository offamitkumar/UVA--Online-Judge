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
    map<char , int> f; 

    f['A']=  2;
    f['B']=  2;
    f['C']=  2;
    f['D']=  3;
    f['E']=  3;
    f['F']=  3;
    f['G']=  4;
    f['H']=  4;
    f['I']=  4;
    f['J']=  5;
    f['K']=  5;
    f['L']=  5;
    f['M']=  6;
    f['N']=  6;
    f['O']=  6;
    f['P']=  7;
    f['Q']=  7;
    f['R']=  7;
    f['S']=  7;
    f['T']=  8;
    f['U']=  8;
    f['V']=  8;
    f['W']=  9;
    f['X']=  9;
    f['Y']=  9;
    f['Z']=  9;
    string s; 
    while(cin >> s){
        for(auto&itr:s){
            if(itr == '-' ||( itr >= '0' && itr <='9')){
                cout << itr; 
            }else{
                cout << f[itr];
            }
        }
        cout << '\n'; 
    }
    return 0;
}
