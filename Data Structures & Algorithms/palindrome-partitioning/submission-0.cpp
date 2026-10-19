class Solution {
public:
    bool palindrome(string& s){
        string ss= s;
        reverse(ss.begin(), ss.end());
        return s==ss;
    }

    void palinpart(string s, vector<string>& partitions, vector<vector<string>>& ans){
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        
        int n= s.length();
        for(int i=0; i<n; i++){
            string part= s.substr(0, i+1);
            if(palindrome(part)){
                partitions.push_back(part);
                palinpart(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;
        palinpart(s, partitions, ans);
        return ans;
    }
};
