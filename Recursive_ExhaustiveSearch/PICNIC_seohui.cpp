/**
 * 재귀 - (한조각 / 나머지 전체) 로 문제를 나눈다
 *
 * 작은 조각 : list에서 두명의 학생을 뽑아서 pair에 있는지 비교하는것.
 *  - 학생을 뽑는게 중복되면 안됨.
 * base : 마지막 두명을 뽑았을 때. count를 1 증가시킨다.
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/**
 * 받은 list 중에2명을 뽑음.
 *
 * @param[in]   pairs   친구 list
 *              sList   학생 전체 list/ 뽑았다 안뽑았다를 boolean으로 표시
 *              sNum    학생 수
 * @param[out]  count
 */
int countN(vector<pair<int, int> >& pairs, bool* sList, int sNum) {
    int answer = 0;

    // 첫번째 학생 뽑기. 가장 숫자 작은학생부터
    int small = -1;
    for (int i = 0; i < sNum; i++) {
        if (sList[i] == 0) {
            small = i;
            break;
        }
    }

    // base : 모든 학생을 뽑았음
    if (small == -1) {
        return 1;
    }
    
    // 두번째 학생 뽑기. pairs 목록에서 뽑는다.
    int second;
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs[i].first == small && sList[pairs[i].second] == 0) {  // 만약에 짝 목록에 첫번째 학생이 있으면. 그 짝이 아직 안뽑혔으면.
            second = pairs[i].second;   // 그 짝을 내 짝으로 만듬
            sList[second] = 1;
            sList[small] = 1;
            
            // 남은 학생에서 두명 뽑기
            answer += countN(pairs, sList, sNum);
            sList[second] = 0;
            sList[small] = 0;
        }
    }
    return answer;
}

int main(void) {
    int testCase;
    int sNum, pNum;
     vector<pair<int, int> > pairs;
    
     cin >> testCase;

    while (testCase--) {
        cin >> sNum >> pNum;
        int p1, p2;

        /* exception handling */
        if (sNum == 2 && pNum == 1) {   // 답 무조건 1개
            cin >> p1 >> p2;
            cout << 1 << endl;
            continue;
        }
       
        // make student list
        bool* sList = new bool[sNum];
        memset(sList, 0, sNum);

        // make friend pair. sorted in pair
        for (int i = 0; i < pNum; i++) {
            cin >> p1 >> p2;
            if (p1 < p2) {
                pairs.push_back(pair<int, int>(p1, p2));
            } else {
                pairs.push_back(pair<int, int>(p2, p1));
            }
        }

        cout << countN(pairs, sList, sNum) << endl;

        pairs.clear();
    }

    return 0;
}
