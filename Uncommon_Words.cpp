// date---> 17/9/2024

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

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

// Main function to test the code
int main() {
    // Creating an instance of the Solution class
    Solution sol;

    // Input strings
    string s1, s2;
    cout << "Enter the first sentence: ";
    getline(cin, s1);  // Reading the first sentence
    cout << "Enter the second sentence: ";
    getline(cin, s2);  // Reading the second sentence

    // Calling the function to get uncommon words
    vector<string> result = sol.uncommonFromSentences(s1, s2);

    // Output the result
    cout << "Uncommon words: ";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
