#include <iostream>
#include <queue>
#include <set>

using namespace std;

/*
  time complexity: 
    2^(n*(n-1)/2) = O(2^(n*n)), n<=10이므로 최대 2^100??? 
    인 것 처럼 보이지만 한 페어가 정해지는 순간 그 페어에 속한 학생들이 들어가는 페어는 모두 생략되므로, 흠,, 정확히 어케 계산되는거지
    페어 5개를 일렬로 정렬할 수 있는 경우의 수인가.. 
  elapsed time: 36ms

  
  사용 알고리즘: 완전 탐색, 재귀호출
  
  재귀호출 조각: 하나의 페어를 넣을 수 있다면 넣거나 뺀다. 나머지 페어에 대하여 마찬가지로 재귀호출로 테스트
  base condition:
    1. 모든 학생이 골라졌다.
    2. 모든 페어가 소진되었다.

  review:
    set안쓰고 그냥 답안처럼 taken[] 쓰는게 더 빠를듯 
*/

int cntCaseAllCouple(queue<pair<int,int>>& couples, set<int>& selected, int nStudent) {
    if (selected.size() == nStudent)
        return 1;
    if (couples.empty())
        return 0;

    int cntCase = 0;
    auto couple = couples.front();
    couples.pop();
    if (!selected.count(couple.first) && !selected.count(couple.second)) {
        selected.emplace(couple.first);
        selected.emplace(couple.second);
        cntCase += cntCaseAllCouple(couples, selected, nStudent); // 넣을 수 있으면 넣어서 
        selected.erase(couple.first);
        selected.erase(couple.second);
    }
    cntCase += cntCaseAllCouple(couples, selected, nStudent); // 안넣은 채로 해보고
    couples.push(couple); // 이게 들어갈 수 있는 경우는 이미 다 해봐서 필요 없음 
    
    return cntCase;
}

int main() {
    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int nStudent;
        int nCouple;
        cin >> nStudent;
        cin >> nCouple;

        queue<pair<int,int>> couples;
        set<int> selected;
        for (int j=0; j<nCouple; j++) {
            int s1;
            int s2;
            cin >> s1;
            cin >> s2;
            couples.emplace(s1, s2);
        }
        cout << cntCaseAllCouple(couples, selected, nStudent) << endl;
    }
}
