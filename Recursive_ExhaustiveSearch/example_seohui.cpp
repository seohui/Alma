#include <iostream>

using namespace std;

// --- 코드 6.1
// 1부터 n 까지의 합을 계산
int recursiveSum(int num) {
  if (num == 1) return 1;
  return num + recursiveSum(num -1);
}
// --- 코드 6.1 

// --- 코드 6.2 
// 0 ~ n 개의 원소 중 m 개를 고르는 모든 조합을 찾는 알고리즘
void pick(int level, int val, int picknum, int num, int* arr) {
  // final level, print answer
  if (level == picknum + 1) {
    for (int k = 0; k < picknum; k++) {
      cout << arr[k] << " ";
    }
    cout << endl;
    return;
  }
  // make branch
  for (int j = val + 1; j <= num - picknum + level; j++) {
    arr[level - 1] = j;
    pick(level + 1, j, picknum, num, arr);
  }
}

// n : 0 ~ n 
// pickn : combination of pick pickn
void Find(int n, int pickn) {
  int level = 1;
  int* arr = new int[pickn];
  
  for (int i = 0; i <= n - pickn + 1; i++) {
    arr[level - 1] = i;
    pick(level + 1, i, pickn, n, arr);
  }
}
// --- 코드 6.2 

int main(void) {
  
  //cout << "sum : "<< recursiveSum(10) << endl;
  cout << "count" << endl;
  Find(5, 4);

  return 0;
}
