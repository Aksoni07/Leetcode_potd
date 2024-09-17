class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        vector<string> ans;
        
        // Process string s1
        int n = s1.length();
        int i = 0;
        while (i < n) {
            while (i < n && s1[i] == ' ') i++;  // Skip spaces
            int temp = i;
            while (i < n && s1[i] != ' ') i++;  // Find the word
            string str = s1.substr(temp, i - temp);  // Get the word
            if (!str.empty()) {
                mp[str]++;  // Increase frequency count
            }
        }

        // Process string s2
        int m = s2.length();
        int j = 0;
        while (j < m) {
            while (j < m && s2[j] == ' ') j++;  // Skip spaces
            int temp = j;
            while (j < m && s2[j] != ' ') j++;  // Find the word
            string str = s2.substr(temp, j - temp);  // Get the word
            if (!str.empty()) {
                mp[str]++;  // Increase frequency count
            }
        }

        // Collect uncommon words
        for (auto& p : mp) {
            if (p.second == 1) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
