/*
  time compelxity : O(4^10)
  elapsed time: 616ms

  사용 알고리즘: 완전 탐색, 재귀호출

  재귀호출 조각: 스위치 0~3번 누르고 다음 스위치를 눌러보라고 재귀호출
  base condition: 
    1. 다 3번씩 눌러봄~
    2. 다 12시 가르킴~

  review:
    1. 큰 수는 상수로 하는 게 좋을듯
    2. 코드를 간단히..  체크하고 push했으면 마지막 경우를 이상하게 체크안해도 됨.
      수식이 더해지니 실수의 여지가 생기는 듯 
*/
#include <iostream>

using namespace std;

const int swtch[10][16] = {
  { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0, 1, 2
  { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 }, // 3, 7, 9, 11
  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1 }, // 4, 10, 14, 15
  { 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0, 4, 5, 6, 7
  { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0 }, // 6, 7, 8, 10, 12
  { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }, // 0, 2, 14, 15
  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }, // 3, 14, 15
  { 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 }, // 4, 5, 7, 14, 15
  { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 1, 2, 3, 4, 5
  { 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 }  // 3, 4, 5, 9, 13
};

int cloc[16];

void pushButton(int swtchNum) {
  for (int i=0; i<16; i++) {
    if (swtch[swtchNum][i]) {
      cloc[i] += 3;
      if (cloc[i] == 12)
        cloc[i] = 0;
    }
  }
}

int optPushCnt(int swtchNum) {
  bool finish = true;
  for (int i=0; i<16; i++) {
    if (cloc[i] != 0) {
      finish = false;
      break;
    } 
  }
  if (finish) { 
    return 0;
  }
  if (swtchNum >= 10)
    return -1;
//  for (int i=0; i<16; i++) {
//    cout << cloc[i] << " ";
//  } 
//  cout << endl;
  int min = (1u<<31)-1; 

  for (int i=0; i<4; i++) { // +3,6,9,12 마지막에 0을 체크함으로써 reset효과
    pushButton(swtchNum);
    int result = optPushCnt(swtchNum+1); 
    if (result >= 0 && min > result+(i+1)%4) {
      min = result+(i+1)%4;
    }
  }
  if (min == (int)((1u<<31)-1)) // result >= 0인 경우가 없었다.
    return -1;
  else
    return min;
}

int main() {
  int C; // test_case

  cin >> C;
  
  for (int i=0; i<C; i++) {
    for (int j=0; j<16; j++) {
      cin >> cloc[j];
      if (cloc[j] == 12)
        cloc[j] = 0;
    }
    cout << optPushCnt(0) << endl;
  }
}
