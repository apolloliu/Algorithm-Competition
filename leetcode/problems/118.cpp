class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows, vector<int>(numRows, 1));
        for(int i = 2; i < numRows; ++i){
            for(int j = 1; j < i; ++j){
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        for(int i = 0; i < numRows; ++i){
            res[i].resize(i+1);
        }
        return res;
    }
};
