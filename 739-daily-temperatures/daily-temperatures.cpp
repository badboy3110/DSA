class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(st.size()!=0&&temperatures[i]>temperatures[st.top()]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};