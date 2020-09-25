#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct Element{
    int First , Second , index;
};
bool compare(const Element&a ,const Element&b) {
    return a.First < b.First;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    vector<Element>v; 
    int a,b; 
    int index_counter{1};
    while (cin >> a >> b) {
        Element e; 
        e.First =a; 
        e.Second =b; 
        e.index = index_counter++;
        v.push_back(e);
    }
    sort(v.begin(), v.end() , compare);
    int n = v.size();
    vector<string>path(n) ;
    vector<int>element(n , 1); 
    for (int i=0; i<n; ++i) {
        path.at(i) = to_string(v.at(i).index)+" ";
    }
    int mxe{1}; 
    string sequence = "1";
    for (int i=1; i<n; ++i) {
        for (int j=0; j<i; ++j) {
            if (v.at(i).First > v.at(j).First && v.at(i).Second < v.at(j).Second) {
                if (element.at(j)+1 > element.at(i)) {
                    path.at(i) = path.at(j) + to_string(v.at(i).index) + " ";
                    element.at(i) = element.at(j)+1;
                    if (element.at(i) > mxe) {
                        mxe = element.at(i); 
                        sequence = path.at(i);
                    }
                }
            }
        }
    }
    cout << mxe << '\n'; 
    istringstream ss(sequence); 
    while (ss >> a) {
        cout << a << '\n'; 
    }
    return 0;
}
