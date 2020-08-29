#include <bits/stdc++.h>
using namespace std;
#define int int64_t
set<char>vowel;
string check(const string&a , const string&b) {
    string No = "No";
    string Yes = "Yes";
    if(a.size() != b.size()){
        return No;
    }
    for(int i=0; i<static_cast<int>(a.size());++i){
        if(a.at(i) != b.at(i) && vowel.find(a.at(i)) == vowel.end()){
            return No;
        }
    }
    return Yes;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t;
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    while (t--) {
        string strA, strB; cin >> strA >> strB;
        cout << check(strA , strB) << endl;
    }
    return 0;
}
