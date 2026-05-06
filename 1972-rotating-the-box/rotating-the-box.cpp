class Solution {
public:
    void rotate(vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<char>> temp(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[j][n - i - 1] = mat[i][j];
            }
        }

        mat = temp;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        rotate(boxGrid);

        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for (int i = 0; i < m; i++) {

            int index = n - 1;

            for (int j = n - 1; j >= 0; j--) {

                if (boxGrid[j][i] == '*') {

                    index = j - 1;
                }

                else if (boxGrid[j][i] == '#') {

                    swap(boxGrid[j][i], boxGrid[index][i]);
                    index--;
                }
            }
        }

        return boxGrid;
    }
};