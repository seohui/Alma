#include <iostream>
#include <cstring>
#include <unistd.h>

using namespace std;

/*
  time complexity: O(4^(50/3))? 그럼 1억 넘는디....
  
  elapsed time : 0ms

  사용 알고리즘: 완전 탐색, 재귀 호출

  재귀 호출 조각: 한 조각 놓을 수 있으면 놓아보고 놓여진 판으로 다시 재귀적으로 테스트
  base condition:
    1. y가 판을 넘어감 ( 빈 공간이 없음)
    2. 놓을 수 있는 방법이 없음 (4가지 경우)

  Review:
    1. 순서강제하기가 생각나서 쓰긴 썻는데, 첨에 이걸 써도 되나 많이 헷갈림. 어떤 순서로 해도 같은 결과에 닿고, 순서가 중요하지 않다면 순서를 강제해도 된다. 
    2. 처음에 시간복잡도가 확실히 계산하고 싶었는데, 잘 계산이 안댐.. 4^(50/3)보다 훨씬 적어질 것 같긴한데.. 얼마나 적어질지..
      흠 책에서도 걍 적을꺼야~ 하고 넘어가네. 괜히 고민한듯
    3. 퍼즐 조각 넣는 코드를 이쁘게 할 수 없을까 고민에 넘 많은 시간소비.. 시간분배 어렵
*/

char board[22][22] = {0,};

void resetBoard() {
  memset(board, '#', 22*22);
}

/*
  x,y: 다음에 블록넣기를 시도할 위치, 놓을 수 있는 위치를 찾아 블록을 놓고  그 다음 좌표를 재귀로 넘긴다. x,y는 증가하기만 한다.
*/
int cntCoverCase(int x, int y, int W, int H) {
  while (board[y][x] == '#') {
    x++;
    if (x > W) {
      x = 0;
      y++;
    }
    if (y > H)
      return 1; // 더이상 빈 공간 없음.
  } 
 /* 
  for (int i=0; i<H+2; i++) {
    for (int j=0; j<W+2; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
   */
  int cnt = 0;
  board[y][x] = '#';
  // 놓을 x,y 찾았다!
  if (board[y][x+1] == '.') {
    if (board[y+1][x]== '.') {
      board[y][x+1] = '#';
      board[y+1][x] = '#';
      cnt += cntCoverCase(x+2, y, W, H);
      board[y][x+1] = '.';
      board[y+1][x] = '.';
    }
    if (board[y+1][x+1] == '.') {
      board[y][x+1] = '#';
      board[y+1][x+1] = '#';
      cnt += cntCoverCase(x+2, y, W, H);
      board[y][x+1] = '.';
      board[y+1][x+1] = '.';
    }
  }
  if (board[y+1][x] == '.') {
    if (board[y+1][x-1] == '.') {
      board[y+1][x] = '#';
      board[y+1][x-1] = '#';
      cnt +=cntCoverCase(x+1, y, W, H);
      board[y+1][x] = '.';
      board[y+1][x-1] = '.';
    }
    if (board[y+1][x+1] == '.') {
      board[y+1][x] = '#';
      board[y+1][x+1] = '#';
      cnt +=cntCoverCase(x+1, y, W, H);
      board[y+1][x] = '.';
      board[y+1][x+1] = '.';

    }
  }
  board[y][x] = '.';
  return cnt; 
}

int main() {
  int C; // test case
  cin >> C;  
  for (int i=0; i<C; i++) {
    resetBoard(); 
    int H, W;
    cin >> H;
    cin >> W;
    for (int j=0; j<H; j++) {
//      cin.getline(&board[j+1][1], W);
      for (int k=0; k<W; k++) {
        cin >> board[j+1][k+1];
      }
    }
    /*
    for (int j=0; j<H+2; j++) {
      for (int k=0; k<W+2; k++) {
        cout << board[j][k];
      }
      cout << endl;
    }
    */
    cout << cntCoverCase(1, 1, W, H) << endl; 
  }
  return 0;
}
