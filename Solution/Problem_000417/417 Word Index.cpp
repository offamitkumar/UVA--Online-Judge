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
    // aa
    int counter=1;
    map<string, int>f;
    for (char ch1='a'; ch1<='z'; ++ch1) {
        string s{}; s=ch1;
        f[s] = counter++;
    }
    for (char ch1='a'; ch1<='z'; ++ch1) {
        for (char ch2=ch1+1; ch2<='z'; ++ch2) {
            string s{};
            s.push_back(ch1); 
            s.push_back(ch2);
            f[s] = counter++;
        }
    }
    // aaa
    for (char ch1='a'; ch1<='z'; ++ch1) {
        for (char ch2=ch1+1; ch2<='z'; ++ch2) {
            for (char ch3=ch2+1; ch3<='z'; ++ch3) {
                string s{};
                s.push_back(ch1); 
                s.push_back(ch2);
                s.push_back(ch3);
                f[s] = counter++;
            }
        }
    }
    // aaaa
    for (char ch1='a'; ch1<='z'; ++ch1) {
        for (char ch2=ch1+1; ch2<='z'; ++ch2) {
            for (char ch3=ch2+1; ch3<='z'; ++ch3) {
                for (char ch4= ch3+1; ch4<='z'; ++ch4) {
                    string s{};
                    s.push_back(ch1); 
                    s.push_back(ch2);
                    s.push_back(ch3);
                    s.push_back(ch4);
                    f[s] = counter++;
                }
            }
        }
    }
    // aaaaa
    for (char ch1='a'; ch1<='z'; ++ch1) {
        for (char ch2=ch1+1; ch2<='z'; ++ch2) {
            for (char ch3=ch2+1; ch3<='z'; ++ch3) {
                for (char ch4= ch3+1; ch4<='z'; ++ch4) {
                    for(char ch5 = ch4+1; ch5<='z'; ++ch5) {
                        string s{};
                        s.push_back(ch1); 
                        s.push_back(ch2);
                        s.push_back(ch3);
                        s.push_back(ch4);
                        s.push_back(ch5);
                        f[s] = counter++;
                    }
                }
            }
        }
    }
    string s; 
    while (cin >> s) {
        cout << f[s] << '\n'; 
    }
    return 0;
}
