#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {

  map<string, int> map;
  map[words[0]]++;

  for (int i = 1; i < words.size(); i++) {
    if (map[words[i]] || words[i].front() != words[i - 1].back())
      return {(i % n) + 1, (i / n) + 1};
    map[words[i]]++;
  }

  return {0, 0};
}