#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string change(string &in, map<string, char> &s) {
  string out = "";

  for (int i = 0; i < in.size(); i++) {
    if (in[i + 1] == '#') {
      out += s[in.substr(i, 2)];
      i++;
    } else
      out += in[i];
  }
  return out;
}
string solution(string m, vector<string> musicinfos) {
  string answer = "(None)";
  int bHour = 0, aHour = 0, bMin = 0, aMin = 0, time = 0, bTime = 0;
  string melody = "", title = "";
  map<string, char> s;

  s["C#"] = 'Q';
  s["D#"] = 'W';
  s["F#"] = 'R';
  s["G#"] = 'T';
  s["A#"] = 'Y';

  melody = change(m, s);

  for (int i = 0; i < musicinfos.size(); i++) {
    string tmp = "", music = "";

    bHour = stoi(musicinfos[i].substr(0, 2)) * 60;
    bMin = stoi(musicinfos[i].substr(3, 2));
    aHour = stoi(musicinfos[i].substr(6, 2)) * 60;
    aMin = stoi(musicinfos[i].substr(9, 2));
    time = (aHour + aMin) - (bHour + bMin);

    for (int j = 12; musicinfos[i].size(); j++) {
      if (musicinfos[i][j] == ',') {
        title = musicinfos[i].substr(12, j - 12);
        tmp = musicinfos[i].substr(j + 1);
        break;
      }
    }

    music = change(tmp, s);

    if (music.size() < time) {
      tmp = music;

      for (int j = 1; j < time / tmp.size(); j++)
        music += tmp;
      for (int j = 0; j < time % tmp.size(); j++)
        music += tmp[j];
    } else
      music = music.substr(0, time);

    if (music.find(melody) != string::npos) {
      if (bTime < time) {
        answer = title;
        bTime = time;
      }
    }
  }
  return answer;
}