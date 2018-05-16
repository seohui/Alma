/*
  Time Complexity : O(n)

  풀이법: pre-order로 DFS를 하되 2,3 자식부터 출력하면 상하반전임
  이를 위해 str을 순회하며 tree를 만들고, 2,3부터 출력

  review:
    1. 와나 왜 어렵게 트리만들고 서치한 것인지.. DivideAndConquer..
    2. DFS하는 해법중에서도, 코드를 간결하게 하다보니 오히려 가독성도 떨어지고, 코드 수정도 어려운 코드가 나온듯함.
      -변수들이 다 포인터로 넘어감
      -인덱스의 증가가 가독성이 떨어짐
*/
#include <iostream>
#include <cstring>
using namespace std;

int tree[1000];

void make_tree(char* str, int strSize, int& baseIndex, int& nextChar) {
  if (nextChar >= strSize)
    return;
  int nextIndex = baseIndex;
  for (int i=0; i<4; i++) {
    if (str[nextChar] == 'x') {
      tree[nextIndex++] = (baseIndex+=4);
      make_tree(str, strSize, baseIndex, ++nextChar);
    } else if (str[nextChar] == 'b') {
      tree[nextIndex++] = -'b';
      ++nextChar;
    } else if (str[nextChar] == 'w') {
      tree[nextIndex++] = -'w';
      ++nextChar;
    }
  }
  return;
}

void print_reverse(int baseIndex) { // pre-order DFS하되 2,3,0,1 순서로 탐색
  int index = baseIndex+2;
  do {
    if (tree[index] != -'b' && tree[index] != -'w') {
      cout << 'x';
      print_reverse(tree[index]);
    }
    else 
      cout << (char)-tree[index]; 
    if (++index == baseIndex+4)
      index = baseIndex;
  } while (index != baseIndex+2);

}

int main() {
  int C; // #test_case

  cin >> C;

  for (int i=0; i<C; i++) {
    char str[1000];
    cin >> str;
    int baseIndex = 1;
    int nextChar = 1;
    tree[0] = 1;
    if (str[0] == 'x') {
      make_tree(str, strlen(str), baseIndex, nextChar);
      cout << 'x';
      print_reverse(1);
      cout << endl;
    }
    else 
      cout << str[0] << endl;
  }
}
