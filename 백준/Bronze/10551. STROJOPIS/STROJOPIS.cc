#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

map<char, int> create_finger_map() {
    map<char, int> finger_map;

    string l_pinky_keys = "`1QAZ";
    for (char c : l_pinky_keys) finger_map[c] = 0;
    finger_map['~'] = 0; finger_map['!'] = 0;

    string l_ring_keys = "2WSX";
    for (char c : l_ring_keys) finger_map[c] = 1;
    finger_map['@'] = 1;

    string l_middle_keys = "3EDC";
    for (char c : l_middle_keys) finger_map[c] = 2;
    finger_map['#'] = 2;

    string l_index_keys = "45RTFGVB";
    for (char c : l_index_keys) finger_map[c] = 3;
    finger_map['$'] = 3; finger_map['%'] = 3; finger_map['^'] = 3;

    string r_index_keys = "67YHNUJM";
    for (char c : r_index_keys) finger_map[c] = 4;
    finger_map['&'] = 4; finger_map['*'] = 4; finger_map['_'] = 4;

    string r_middle_keys = "8IK,";
    for (char c : r_middle_keys) finger_map[c] = 5;
    finger_map['('] = 5; finger_map['<'] = 5;

    string r_ring_keys = "9OL.";
    for (char c : r_ring_keys) finger_map[c] = 6;
    finger_map[')'] = 6; finger_map['>'] = 6;

    string r_pinky_keys = "0P;/'[]\\-="; 
    for (char c : r_pinky_keys) finger_map[c] = 7;
    finger_map['+'] = 7; finger_map['{'] = 7; finger_map['}'] = 7; finger_map['|'] = 7;
    finger_map[':'] = 7; finger_map['"'] = 7; finger_map['?'] = 7; 
    
    return finger_map;
}

void solve() {
    string input_str;
    if (!(cin >> input_str)) return;

    vector<int> finger_counts(8, 0);

    map<char, int> finger_map = create_finger_map();

    for (char c : input_str) {
        if (finger_map.count(c)) {
            int finger_index = finger_map.at(c);
            finger_counts[finger_index]++;
        } else if (finger_map.count(tolower(c))) {
            int finger_index = finger_map.at(tolower(c));
            finger_counts[finger_index]++;
        }
    }

    for (int count : finger_counts) {
        cout << count << '\n';
    }
}

int main() {
    solve();
    return 0;
}