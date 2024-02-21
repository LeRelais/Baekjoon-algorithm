#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Trie {
private:
    Trie* node[26];
public:
    Trie() {
        for (int i = 0; i < 26; i++) {
            node[i] = NULL;
        }
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (node[i] != NULL)
                delete node[i];
        }
    }

    int toLowerCase(char c) {
        return tolower(c) - 'a';
    }

    void insert(const char* word) {
        if (*word == '\0')
            return;

        int next = toLowerCase(*word);

        if (!node[next])
            node[next] = new Trie();

        node[next]->insert(word + 1);
    }

    bool find(const char* word) {
        int next = toLowerCase(*word);

        if (*word == '\0')
            return true;
        else if (!node[next])
            return false;

        return node[next]->find(word + 1);
    }
};

int n, m;
char s[501];

int main() {
    Trie trie;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie.insert(s);
    }

    int count = 0;

    for (int i = 0; i < m; i++) {
        cin >> s;
        if (trie.find(s))
            count++;
    }
    cout << count;
    return 0;
}