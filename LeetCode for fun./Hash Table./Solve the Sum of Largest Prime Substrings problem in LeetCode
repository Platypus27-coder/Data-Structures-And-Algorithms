class Solution {
public:
    int is_prime(string s, int l, int r) {
        string tmp = ""; 
        for (int i = l; i < r; i++) {
            tmp += s[i]; 
        }
        long long n = stoll(tmp);
        if (n < 2) return 0;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) 
                return 0; 
        }
        return 1; 
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size(); 
        map<long long, int> mp; 
        vector<long long> result; 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (is_prime(s, i, j)) {
                    string tmp = "";
                    for (int k = i; k < j; k++) {
                        tmp += s[k];  
                    }
                    long long res = stoll(tmp); 
                    if (mp[res] == 0) {
                        result.push_back(res);
                        mp[res]++; 
                    }
                }
            }
        }
        if (result.size() < 3) {
            long long sum = 0; 
            for (int i = 0; i < result.size(); i++) {
                sum += result[i]; 
            }
            return sum; 
        }
        sort(result.begin(), result.end());
        int len = result.size();
        return result[len - 1] + result[len - 2] + result[len - 3]; 
    }
};
