//Leetcode 3:Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int ans = 0;
        int start = 0;

        for(int i=0;i<s.length();i++)
        {
            if(window.find(s[i]) == window.end())
            {
                window.insert(s[i]);
            }
            else
            {
               while(s[start] != s[i]) //this modifictaion is required for a repating character as in test case 3 pww
               {
                   window.erase(s[start]);
                   start++;
               }

               start++; //to start from second repeating characters
            }

            ans = max(ans,i-start+1);
        }

        return ans;
    }
};
