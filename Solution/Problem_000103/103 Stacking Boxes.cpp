#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int Index = 1;
struct Box{
    int index; 
    vector<int>dia;
    Box(){}
    Box(int n){
        dia.resize(n);
    }
    friend istream& operator>>(istream&cin , Box &b1) {
        b1.index = Index++; 
        for(int i=0; i<(int)b1.dia.size(); ++i) {
            cin >> b1.dia.at(i); 
        }
        sort(b1.dia.begin() , b1.dia.end());
        return cin;
    }
};
bool compare(Box &b1 , Box& b2) {
    for(int i=0; i < (int)b1.dia.size(); ++i) {
        if (b1.dia.at(i) < b2.dia.at(i)) {
            return true;
        }else if(b1.dia.at(i) > b2.dia.at(i)) {
            return false;
        }
    }
    return false;
}
bool comp( Box &b1 , Box&b2) {
    for(int i =0; i < (int)b1.dia.size(); ++i) {
        if(b2.dia.at(i) >= b1.dia.at(i)) {
            return false;
        }
    }
    return true;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int k ,n; 
    while (cin >> k >> n) {
        Index =1;
        vector<Box>box(k, Box(n));
        for (int i=0; i < k; ++i) {
            cin >> box.at(i);
        }
        sort(box.begin(), box.end(), compare);
        vector<string>path(k);
        for(int i=0; i < k; ++i) {
            path.at(i) += to_string(box.at(i).index);
        }
        vector<int>sol(k , 1); 
        int max_stacking{1}; 
        string stacks = path.at(0); 
        for (int i=1; i<k; ++i) {
            string temp_path;
            for (int j=0; j < i; ++j) {
                if ( comp(box.at(i) , box.at(j)) ) {
                    if (sol.at(i) < sol.at(j)+1) {
                        sol.at(i) = sol.at(j)+1; 
                        temp_path = path.at(j);
                    }
                }
            }
            path.at(i) = temp_path+" "+path.at(i);
            if (max_stacking < sol.at(i)) {
                max_stacking = sol.at(i);
                stacks = path.at(i);
            }
        }
        cout << max_stacking << '\n'; 
        cout << stacks << '\n'; 
    }
    return 0;
}
