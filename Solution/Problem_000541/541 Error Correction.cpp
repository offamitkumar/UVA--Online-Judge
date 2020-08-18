#include <bits/stdc++.h>
using namespace std;
#define int int64_t
pair<int,int> odd(vector<int>&v){
    int counter{};
    int odd_index;
    for(int i=0; i<(int)v.size();++i){
        if(v.at(i)&1){
            odd_index = i;
            counter++;
        }
    }
    return make_pair(counter , odd_index);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; 
    while(cin >> t,t){
        vector<vector<int>> v(t, vector<int>(t , 0));
        for(int i=0; i<t; ++i){
            for(int j=0; j<t;++j){
                cin >> v.at(i).at(j);
            }
        }
        vector<int>horiz(t) , verti(t);
        for(int i=0; i<t; ++i){
            for(int j=0; j < t; ++j){
                horiz.at(i) += v.at(i).at(j);
            }
        }
        for(int i=0; i<t; ++i){
            for(int j=0; j < t; ++j){
                verti.at(i) += v.at(j).at(i);
            }
        }
        auto x = odd(horiz); // return count of odd number and index of last odd number (if multiple are present)
        auto y = odd(verti); 
        if(x.first == 0 && y.first == 0){
            cout << "OK" ;
        }else if(x.first > 1 || y.first  > 1 || (x.first ^ y.first)){
            cout << "Corrupt";
        }else{
            cout <<"Change bit ("<<x.second+1 << "," << y.second+1 << ")";
        }
        cout << '\n'; 
    }
    return 0;
}
