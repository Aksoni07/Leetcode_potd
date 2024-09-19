#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert all integers in the vector to strings
        vector<string> v;
        for(int i : nums) {
            v.push_back(to_string(i));
        }

        // Sort strings based on the concatenation of two strings (custom sorting)
        sort(v.begin(), v.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // Concatenate all strings in sorted order
        string result = "";
        for(string &s : v) {
            result += s;
        }

        // Handle case where the largest number is 0 (e.g., [0, 0])
        if(result[0] == '0') {
            return "0";
        }

        return result;
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {10, 2};
    Solution sol;
    cout << "Largest number for nums1: " << sol.largestNumber(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {3, 30, 34, 5, 9};
    cout << "Largest number for nums2: " << sol.largestNumber(nums2) << endl;

    // You can add more test cases below
    return 0;
}
