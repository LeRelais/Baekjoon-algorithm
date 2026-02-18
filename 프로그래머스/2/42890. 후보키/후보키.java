import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    public int solution(String[][] relation) {
        int answer = 0;
        int colLen = relation.length;
        int rowLen = relation[0].length;
        List<Integer> candidateKeys = new ArrayList<>();
        
        for(int i = 1; i < (1 << rowLen); i++){
            if(isUnique(i, relation, rowLen, colLen)){
                if(isMinimal(i, candidateKeys)){
                    candidateKeys.add(i);
                }
            }
        }
        return candidateKeys.size();
    }
    
    public boolean isUnique(int subset, String[][] relation, int rowLen, int colLen){
        HashSet<String> set = new HashSet<>();
        
        for(int i = 0; i < colLen; i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j < rowLen; j++){
                if((subset & (1 << j)) != 0){
                    sb.append(relation[i][j]).append(",");
                }
            }
            set.add(sb.toString());
        }
        return set.size() == colLen;
    }
    
    public boolean isMinimal(int subset, List<Integer> keys){
        for(int key : keys){
            if((subset & key) == key) return false;
        }
        return true;
    }
}