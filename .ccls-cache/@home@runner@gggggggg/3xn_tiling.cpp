#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

long long arr[5001];

int solution(int n) {
  int answer = 0;
  if (n % 2 != 0)
    return 0;
  arr[0] = 1;
  arr[2] = 3;

  for (int i = 4; i <= n; i += 2) {
    arr[i] = (arr[i - 2] * 3);
    for (int j = 0; j <= i - 4; j += 2) {
      arr[i] += (arr[j] * 2) % MOD;
    }
    arr[i] %= MOD;
  }

  answer = arr[n] % MOD;

  return answer;
}