class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int count = 0;
        int total = n*m;
        vector<int>ans;

        int rowstart = 0;
        int colstart = 0;
        int rowend = n-1;
        int colend = m-1;

        while(count < total)
        {
            //rowstart ko chalayege , colstart->colend tak
            for(int i=colstart ; i<=colend ; i++)
            {
                ans.push_back(matrix[rowstart][i]);
                count += 1;
            }
            rowstart += 1;
            if(count == total) break;

            //colend ko chalayege , rowstart->rowend tak
            for(int i=rowstart ; i<=rowend ; i++)
            {
                ans.push_back(matrix[i][colend]);
                count += 1;
            }
            colend -= 1;
            if(count == total) break;

            //rowend ko chalayege , colend->colstart tak
            for(int i=colend ; i>=colstart ; i--)
            {
                ans.push_back(matrix[rowend][i]);
                count += 1;
            }
            rowend -= 1;
            if(count == total) break; 

            //colstart ko chalayege , rowend->rowstart tak
            for(int i=rowend ; i>=rowstart ; i--)
            {
                ans.push_back(matrix[i][colstart]);
                count += 1;
            }
            colstart += 1;
            if(count == total) break;          
        }
        return ans;
    }
};