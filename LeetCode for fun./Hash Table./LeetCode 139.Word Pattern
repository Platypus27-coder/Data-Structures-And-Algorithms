class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;
        map<string, char> mp_prev;
        vector<string> res; 
        stringstream ss(s);
        string word; 
        while(ss >> word) {
            res.push_back(word);
        }
        if (res.size() != pattern.size()) 
            return false;
        for (int i = 0; i < pattern.size(); i++) {
            if (mp.find(pattern[i]) != mp.end()) {
                if (mp[pattern[i]] != res[i]) {
                    return false;
                }
            }
            else {
                if (mp_prev.find(res[i]) != mp_prev.end()) {
                    return false; 
                }
                mp[pattern[i]] = res[i];
                mp_prev[res[i]] = pattern[i];
            }
        }
        return true; 
    }
};
