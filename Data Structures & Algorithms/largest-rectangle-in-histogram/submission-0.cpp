class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n= heights.size();
        int max_area= 0;
        for(int i=0; i<=n; i++){
            while(!st.empty()){
                if(i==n || heights[st.top()]>heights[i]){
                    int h= heights[st.top()];
                    st.pop();
                    int width;
                    if(st.empty()){
                        width= i;
                    } else{
                        width= i- st.top() -1;
                    }
                    int area= h*width;
                    max_area= max(max_area, area);
                } else{
                    break;
                }
            }
            if(i<n){
                st.push(i);
            }
        }
        return max_area;
    }
};
