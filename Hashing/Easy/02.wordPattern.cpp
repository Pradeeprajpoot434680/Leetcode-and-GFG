    #include <bits/stdc++.h>
    using namespace std;
    bool wordPattern(string pattern, string s) {
        // Split the string s into words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            if (charToWord.count(c)) {
                if (charToWord[c] != w) {
                    return false;
                }
            } else {
                charToWord[c] = w;
            }

            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) {
                    return false;
                }
            } else {
                wordToChar[w] = c;
            }
        }

        return true; 
    }

    int main() {
        string pattern = "abba";
        string s = "dog cat cat dog";
        cout << (wordPattern(pattern, s) ? "true" : "false") << endl; // Output: true
        return 0;
    }