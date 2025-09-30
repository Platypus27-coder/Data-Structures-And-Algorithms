class Solution {
public:
    vector<vector<string>> ans;

    bool isPalind(string &s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l; --r;
        }
        return true;
    }

    void backtrack(vector<string> &pali, string &s, int index) {
        if (index == s.size()) {
            ans.push_back(pali);;
            return;
        }
        for (int i = index; i < s.size(); i++) {
            string part = s.substr(index, i - index + 1);
            if (isPalind(part)) {
                pali.push_back(part);
                backtrack(pali, s, i + 1);
                pali.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> pali;
        backtrack(pali, s, 0);
        return ans;
    }
};
