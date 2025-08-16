class Solution {
public:
    vector<string> res;

    void backtrack(int id, string tmp, unordered_map<char, string> &digitToLetters, string digits, char c) {
        if (id == digits.size()) {
            res.push_back(tmp);
            return;
        }
        string letters = digitToLetters[c];
        for (char c : letters) {
            backtrack(id + 1, tmp + c,digitToLetters, digits, digits[id + 1]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string tmp = "";
        backtrack(0, tmp, digitToLetters, digits, digits[0]);
        return res;
    }
};
