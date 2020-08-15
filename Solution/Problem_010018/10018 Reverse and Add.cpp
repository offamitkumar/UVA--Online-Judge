#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool anagram(const string&s){
    int left = 0 , right = s.size()-1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        ++left; 
        --right;
    }
    return true;
}
int add(int num){
    int temp = num; 
    int reverse_num{};
    while(temp){
        reverse_num*=10; 
        reverse_num+=(temp%10); 
        temp/=10;
    }
    return (num + reverse_num);
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
        int num; cin >> num;
        int counter{};
        while(!anagram(to_string(num))){
            ++counter;
            num = add(num);
        }
        cout << counter <<' ' << num << '\n'; 
    }
    return 0;
}
