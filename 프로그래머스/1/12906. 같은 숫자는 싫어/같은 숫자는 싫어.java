import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    Queue<Integer> q = new LinkedList<>();
    public int[] solution(int []arr) {
        int[] answer = {};
        ArrayList<Integer> tmp = new ArrayList<>();
        
        for(int i = 0; i < arr.length; i++){
            if(tmp.isEmpty()){
                tmp.add(arr[i]);
            }
            else{
                if(tmp.get(tmp.size()-1) == arr[i])
                    continue;
                tmp.add(arr[i]);
            }
        }
        answer = new int[tmp.size()];
        
        for(int i = 0; i < tmp.size(); i++){
            answer[i] = tmp.get(i);
        }
        return answer;
    }
}