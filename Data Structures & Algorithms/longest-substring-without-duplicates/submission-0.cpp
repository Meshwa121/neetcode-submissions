class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0; int j=0; int k=0;
        unordered_set<char> st;
        while(j<s.length()){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                k= max(k, j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return k;
    }
};
