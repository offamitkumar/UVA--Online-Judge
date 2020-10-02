#include <bits/stdc++.h>
using namespace std;
#define int int64_t
class Comparator {
    public: 
        bool operator()(const pair<int,int>&a, const pair<int,int>&b) const {
            return a.first > b.first; // min 
        }
};
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int k; 
    while (cin >> k) {
        vector<int>v(k) , v1(k);
        for (int i=0; i<k; ++i) {
            cin >>v1.at(i);
        }
        for (int i=1; i<k; ++i) {
            for (int j=0; j<k; ++j) {
                cin >> v.at(j);
            }
            sort(v.begin(), v.end()); 
            priority_queue<pair<int,int> , vector<pair<int,int>>, Comparator>q; 
            for (int j=0; j<k; ++j) {
                q.push({v1.at(j)+v.at(0), 0});
            }
            for (int j=0; j<k; ++j) {
                auto p = q.top(); q.pop(); 
                v1.at(j) = p.first; 
                if(p.second+1 <k)
                    q.push({p.first-v.at(p.second)+v.at(p.second+1), p.second+1});
            }
        }
        for (int i=0; i<k; ++i) {
            cout << v1.at(i);
            if (i+1 <k) {
                cout << ' ';
            }
        }
        cout << '\n'; 
    }
    return 0;
}
