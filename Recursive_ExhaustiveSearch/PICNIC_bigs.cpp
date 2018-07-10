#include <iostream>
#include <queue>
#include <set>

using namespace std;

/*

*/

int cntCaseAllCouple(queue<pair<int,int>>& couples, set<int>& selected, int nStudent) {
    if (selected.size() == nStudent)
        return 1;
    if (couples.empty())
        return 0;

    int nCouple = couples.size();
    int cntCase = 0;
    for (int i=0; i<nCouple; i++) {
        auto couple = couples.front();
        bool isSelected = false;
        couples.pop();
        if (!selected.count(couple.first) && !selected.count(couple.second)) {
            isSelected = true;
            selected.emplace(couple.first);
            selected.emplace(couple.second);
        }
        cntCase += cntCaseAllCouple(couples, selected, nStudent);
        if (isSelected) {
            selected.erase(couple.first);
            selected.erase(couple.second);
        }
        // couples.push(couple); // 이게 들어갈 수 있는 경우는 이미 다 해봐서 필요 없음 
    }
    
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
