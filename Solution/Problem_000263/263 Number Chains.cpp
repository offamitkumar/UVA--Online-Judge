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
    string strNum;
    while(cin >> strNum && strNum!="0"){
        string prevNum = "asdfasdfa";
        printf("Original number was %s\n",strNum.c_str());
        int chainLenghtCounter = 0;
        set<string>s;
        while(s.find(strNum) == s.end()){
            s.insert(strNum);
            prevNum = strNum;
            ++chainLenghtCounter;
            sort(strNum.begin(), strNum.end(), greater<char>());
            stringstream ss(strNum); 
            int tempNumOne; ss >> tempNumOne;
            reverse(strNum.begin(), strNum.end());
            stringstream ss1(strNum);
            int tempNumTwo; ss1 >> tempNumTwo; 
            int result = tempNumOne - tempNumTwo;
            printf("%ld - %ld = %ld\n", tempNumOne, tempNumTwo, result);
            strNum = to_string(result);
        }
        printf("Chain length %ld\n\n", chainLenghtCounter);
    }
    return 0;
}
