#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> seq;
int S;

int cache[10][100];
int partSum[101];
int partSSum[101];

int diff(int start, int end) {
    int sum = partSum[end]-partSum[start];
    int avg = (int)round(((float)sum)/(end-start));
    int diff = partSSum[end]-partSSum[start]-2*avg*sum+avg*avg*(end-start);
    return diff;
}

int quant(int start, int group) {
    if (start == seq.size()) {
        return 0;
    }
    int& ret = cache[group-1][start];
    if (ret != -1)
        return ret;
    if (group == 1)
        return ret = diff(start, seq.size());
    int m = 987654321;
    for (int i=start+1; i <= seq.size(); i++) {
        m = min(m, diff(start, i)+quant(i, group-1));
    }
    return ret = m;
}


int main() {
    int T, N;
    int in;
    scanf("%d", &T);
    for (int j=0; j<T; j++) {
        scanf("%d %d", &N, &S);
        memset(cache, -1, sizeof(int)*10*100);
        for (int i=0; i<N; i++) {
            scanf("%d", &in);
            seq.push_back(in); 
        }
        sort(seq.begin(), seq.end());
        partSum[0] = 0;
        partSSum[0] = 0;
        for (int i=1; i<=N; i++) {
            partSum[i] = seq[i-1] + partSum[i-1];
            partSSum[i] = seq[i-1]*seq[i-1] + partSSum[i-1];
        }
        printf("%d\n", quant(0, S));
        seq.clear();
    }
    return 0;
}
