#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
  int N = enemy.size();
  int i = 0;
  for (; i < N; i++) {
    if (n >= enemy[i]) {
      n -= enemy[i];
      pq.push(enemy[i]);
    } else {
      if (!k)
        break;
      if (!pq.empty() && (pq.top() > enemy[i])) {
        n += pq.top();
        pq.pop();
        n -= enemy[i];
        pq.push(enemy[i]);
      }
      k--;
    }
  }
  return i;
}