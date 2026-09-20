class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int l  = 0,r = n-1;
        while(l<r){
            int leftHeight = heights[l];
            int rightHeight = heights[r];
            int width = r-l;
            int area = width*min(leftHeight,rightHeight);
            cout << area << endl;
            ans = max(ans,area);
            if(leftHeight < rightHeight){
                l++;
            }
            else{
                r--;
            }
        }


        return ans;
    }
};
