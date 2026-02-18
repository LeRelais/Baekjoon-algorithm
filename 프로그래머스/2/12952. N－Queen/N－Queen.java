class Solution {
    int answer = 0;
    public int solution(int n) {
        int[][] board = new int[n][n];
        boolean[][] used = new boolean[n][n];
        
        for(int i = 0; i < n; i++){
            if(!used[0][i]){
                used[0][i] = true;
                find_comb(used, 1, n);
                used[0][i] = false;
            }
        }
        return answer;
    }
    
    public void find_comb(boolean[][] used, int col, int n){
        if(col == n){
            answer++;
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isValid(used, col, i, n)){
                used[col][i] = true;
                find_comb(used, col+1, n);
                used[col][i] = false;
            }
        }
    }
    
    public boolean isValid(boolean[][] used, int col, int row, int n){
        for(int i = 0; i < col; i++){
            if(used[i][row] == true)
                return false;
        }
        
        for(int i = 1; col-i >= 0 && row-i >= 0; i++){
            if(used[col-i][row-i] == true)
                return false;
        }
        
        for(int i = 1; col-i >= 0 && row+i < n; i++){
            if(used[col-i][row+i] == true)
                return false;
        }
        
        return true;
    }
}