#include <iostream>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

#define MAX 100000

int score[10000] = {0,};
string input;

int getPartScore(int s, int e) {
    if (e > input.length())
        return MAX; 
    int pre = input[s];
    bool same = false;
    bool progressive = true;
    bool mono = true;
    bool alt = true;
    if (input.substr(s, e-s) == string(e-s, input[s]))
        return 1;
    for (int i=s; i<e-2; i++) {
        if (input[i+1]-input[i] != input[i+2]-input[i+1])
            progressive = false;
    }
    if (progressive) {
        for (int i=s; i<e-1; i++) {
            if (abs(input[i]-input[i+1]) != 1)
                mono = false;
        }
        if (mono)
            return 2;
    }
    for (int i=s+2; i<e; i++) {
        if (input[i] != input[i-2])
            alt = false;
    }
    if (alt) 
        return 4;
    if (progressive)
        return 5;
    return 10;
}

int strScore(int s_idx) {
    int maxLen = input.length();
    if (s_idx == maxLen)
        return 0;
    if (s_idx+2 >= maxLen)
        return MAX;
    int& ret = score[s_idx];
    if (ret != 0)
        return ret;
    int m = 0;
    m = min(getPartScore(s_idx, s_idx+3)+strScore(s_idx+3),
                getPartScore(s_idx, s_idx+4)+strScore(s_idx+4));
    ret = min(m, getPartScore(s_idx, s_idx+5)+strScore(s_idx+5));
    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> input;
        cout << strScore(0) << endl;
        memset(score, 0, 10000*sizeof(int));
    }
    return 0;
}
