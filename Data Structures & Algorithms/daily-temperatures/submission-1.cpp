class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n= temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first<=temperatures[i]){
                st.pop();
            }
                if(st.empty()){
                    ans[i]=0;
                }
                else if(!st.empty() && st.top().first>temperatures[i]){
                    int ind= st.top().second- i;
                    ans[i]= ind;
                }
            
            st.push({temperatures[i], i});
        }
        return ans;
    }
};
