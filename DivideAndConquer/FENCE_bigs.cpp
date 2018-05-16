/*
  Time Complexity: O(nlogn)
    매 fence가 들어올때마다 ordered_map를 binary search

  풀이법: divide and conquer를 쓴건가.. 이진탐색이 분할정복이긴한데.. 이런게 아닌 것 같은데..
   여튼 매번 펜스가 들어올 때마다 넓이가 고정되는 사각형들의 크기를 구해서 max값을 구함. 고정 시키는 시점은 이전 펜스보다 낮은게 들어오면, 더 높은 펜스들의 height을 쓰는 펜스들의 넓이는 다 고정됨.
   지금들어온 것 보다 큰거중에 제일 작은 것(맨 왼쪽에 있는 것)은 닫게 만든 펜스높이로 깎아준다.

  review: 
    하.. 첨에 생각했던 방법이 책에 있던 방법인데, 합칠때마다 n의 탐색을 해야하네? 그럼 n^2이라고 생각... 나누니까 n을 logn번 해야하는건데 왜 n이라고 생각했지.. 
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
  int C; // #test_case
  map<int, int> openHeight;

  cin >> C;
  for (int i=0; i<C; i++) {
    int N;
    cin >> N;
    int max = 0;
    int preH = -1;
    for (int j=0; j<N+1; j++) {
      int h = 0;
      if (j != N) //마지막에 0을 넣기 위해 
        cin >> h;
      if (preH < h) { // open
        openHeight.emplace(h, j);
      } else if (preH > h) { // close
        auto base = openHeight.upper_bound(h);
        int baseIndex = base->second;
        // remove를 위해 base를 유지
        auto it = base;
        for(; it != openHeight.end(); it++) {
          int area = (j-it->second)*(it->first);
          if (area > max)
            max = area;
        }
        openHeight.erase(base, it); // erase [base, it(end))
        openHeight.emplace(h, baseIndex); // 큰 거 중에 가장 작은 놈은 깍아서 넣자~
      } 
      preH = h;
    }
    cout << max << endl;
  }
  return 0;
}
