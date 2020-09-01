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
    int n;cin >> n;
    cin.ignore();
    string s;
    while(n--){
        getline(cin , s);
        stringstream ss(s);
        pair<pair<int,int>, pair<int,int>> p {{0,0},{0,0}};
        int counter{};
        while(ss >> s){
            ++counter;
            if(s.at(0) == 'M'){
                p.first.first++;
            }else{
                p.first.second++;
            }
            if(s.at(1) == 'M'){
                p.second.first++;
            }else{
                p.second.second++;
            }
        }
        if(counter>1 && (p.first.second == p.second.first) && (p.first.first == p.second.second)){
            cout <<"LOOP" << endl;
        }else{
            cout <<"NO LOOP" << endl;
        }
    }
    return 0;
}
