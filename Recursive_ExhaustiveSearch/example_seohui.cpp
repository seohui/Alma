#include <iostream>

using namespace std;

int recursiveSum(int num) {
  if (num == 1) return 1;
  return num + recursiveSum(num -1);
}

// 0 ~ n 개의 원소 중 네 개를 고르는 모든 경우를 출력
void pick(int l, int val, int n) {
  if (l == 5) {
    cout << endl;
    return;
  }
  for (int j = n; j < n - 4 + l; j++) {
    cout << n << " ";
    pick(l + 1, j + 1, n);
  }
}

void Find(int n) {
  int level = 1;
  for (int i = 0; i <= n-3; i++) {
    cout << i << " ";
    pick(level + 1, i + 1, n);
  }
}


int main(void) {
  
  //cout << "sum : "<< recursiveSum(10) << endl;
  cout << "count" << endl;
  Find(5);

  return 0;
}
