vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> result;
    int rows = matrix.size();
    if (rows == 0) return result;
    int cols = matrix[0].size();
    if (cols == 0) return result;
    int level = ((rows<cols?rows:cols) + 1)/2;
    
    
    for (int i=0; i<level; i++) {   //层数
        int col_begin = 0+i;
        int col_end = cols-i-1;
        int row_begin = 0+i;
        int row_end = rows-i-1;

        for (int j=col_begin; j<=col_end; j++)        //上
            result.push_back(matrix[row_begin][j]); 

        for (int j=row_begin+1; j<=row_end; j++)     // 右
            result.push_back(matrix[j][col_end]);

        for (int j=col_end-1; j>=col_begin && row_end>row_begin; j--)     // 下
            result.push_back(matrix[row_end][j]);

        for (int j=row_end-1; j>row_begin && col_end>col_begin; j--)     // 左
            result.push_back(matrix[j][col_begin]);
    }

    return result;

}