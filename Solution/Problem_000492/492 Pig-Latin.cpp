#include <bits/stdc++.h>
using namespace std;
#define int int64_t
string process(string &s) {
    set<char>vow; 
    vow.insert('a');
    vow.insert('e');
    vow.insert('i');
    vow.insert('o');
    vow.insert('u');
    string res; 
    if (vow.find(char(tolower(s[0]))) != vow.end()) {
        res+=(s+"ay");
    }else{
        res=(s.substr(1,s.size()-1));
        res+=s[0];
        res+="ay";
    }
    return res;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s; 
    while (getline(cin , s)) {
        for (int i=0; i<(int)s.size(); ++i) {
            string res;
            while ( i<(int)s.size() && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))){
                res+=s[i];
                ++i;
            }
            if(res.size()){
                string p = process(res); 
                cout << p ;
            }
            if(i < (int)s.size()) {
                cout << s[i];
            }
        }
        cout << '\n'; 
    }
    return 0;
}
