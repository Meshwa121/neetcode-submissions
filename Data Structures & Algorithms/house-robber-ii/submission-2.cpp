class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        int n= end-start+1;
        vector<int> dp(n, 0);
        dp[0]= nums[start];
        if(n==1) return dp[0];
        dp[1]= max(nums[start], nums[start+1]);
        for(int i=2; i<n; i++){
            dp[i]= max(nums[start+i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
       int n= nums.size();
       if(n==1) return nums[0];
       return max(solve(nums, 0, n-2), solve(nums, 1, n-1)); 
        }
};
