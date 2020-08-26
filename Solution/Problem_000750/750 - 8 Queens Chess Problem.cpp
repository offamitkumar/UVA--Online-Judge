#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bitset<10>row , d1 , d2; 
vector<int>v(8);
int x, y;
set<string>s;
void nQueen(int r, int queen, int counter){
    if(queen  == 8){
        string st;
        for(auto&itr:v){
            st+=to_string(itr);
        }
        s.insert(st);
        return;
    }
    if(r == x) {
        nQueen(r+1, queen+1, counter+1);
        return;
    }
    for(int i=0; i<8;++i){
        if(!row[i] && (!d1[r-i+7]) && (!d2[r+i])){
            row[i] = d1[r-i+7] = d2[r+i] = 1;
            v[i] = counter;
            nQueen(r+1 , queen+1, counter+1);
            row[i] = d1[r-i+7] = d2[r+i] = 0;
        }
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
    int t; cin >> t; 
    while(t--){
        row.reset();
        d1.reset();
        s.clear();
        d2.reset();
        int t_counter = 1;
        cin >> x >> y; --x; --y;
        row[y] = d1[x-y+7] = d2[x+y] = 1;
        v[y]=x+1;
        nQueen(0, 0,1);
        cout <<"SOLN       COLUMN" << '\n'; 
        cout <<" #      1 2 3 4 5 6 7 8" << '\n';
        cout << '\n'; 
        for(auto&itr:s){
            cout <<setw(2) << setfill(' ')<< t_counter++ << "     "; 
            bool more = true;
            for(auto&it:itr){
                if(more){
                    cout  << ' ';
                }
                more = true;
                cout << it;
            }
            cout << '\n'; 
        }
        if(t){
            cout<<'\n';
        }
    }
    return 0;
}
