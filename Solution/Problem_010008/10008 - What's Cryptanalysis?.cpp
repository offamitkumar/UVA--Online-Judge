#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool compare(tuple<int , int >&a ,tuple<int , int>&b){
    if(get<1>(a) == get<1>(b)){
        return get<0>(a) < get<0>(b);
    }else{
        return get<1>(a) > get<1>(b);
    }
}

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    vector<tuple<int , int >> v; // int(char) , freq 
    for(int i=0; i<26; ++i){
        v.push_back(make_tuple(i,-1));
    }
    int n; cin >> n; cin.ignore();
    string s;
    while(getline(cin , s)){
        for(int i=0; i<(int)s.size(); ++i){
            if(s[i]>='a' && s[i] <='z'){
                int x = (s[i]-'a');
                if(get<1>(v.at(x)) == -1){
                    get<1>(v.at(x)) = 1;
                }else{
                    get<1>(v.at(x)) += 1;
                }
            }else if(s[i]>='A' && s[i]<='Z'){
                int x = (char(tolower(s[i]))-'a');
                if(get<1>(v.at(x)) == -1){
                    get<1>(v.at(x)) = 1;
                }else{
                    get<1>(v.at(x)) += 1;
                }
            }
        }
    }
    sort(v.begin() , v.end() , compare);
    for(int i=0; i<(int)v.size(); ++i){
        if(get<1>(v.at(i)) == -1){
            continue;
        }else{
            cout << char(toupper(char(get<0>(v.at(i))+'a'))) <<' ' << get<1>(v.at(i)) <<"\n"; 
        }
    }
    return 0;
}
