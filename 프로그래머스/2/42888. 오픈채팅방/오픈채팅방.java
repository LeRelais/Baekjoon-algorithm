import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    HashMap<String, String> hm = new HashMap<String, String>();
    ArrayList<String[]> arr = new ArrayList<>();
    
    public String[] solution(String[] record) {
        String[] answer = {};
        ArrayList<String> res = new ArrayList<String>();
        
        for(int i = 0; i < record.length; i++){
            StringTokenizer st = new StringTokenizer(record[i]);
            ArrayList<String> tmp = new ArrayList<String>();
            while(st.hasMoreTokens()){
                tmp.add(st.nextToken());
            }
            
            String ac = tmp.get(0);
            String id = tmp.get(1);
            String name;
            if(!(tmp.get(0).equals("Leave"))){
                name = tmp.get(2);
                hm.put(id, name);
            }
            
            if(!(tmp.get(0).equals("Change"))){
                arr.add(new String[]{ac, id});
            }
        }
        
        for(int i = 0; i < arr.size(); i++){
            String tmp = "";
            
            tmp += hm.get(arr.get(i)[1]) + "님이 ";
            
            if(arr.get(i)[0].equals("Enter")){
                tmp += "들어왔습니다.";
            }
            else
                tmp += "나갔습니다.";
            
            res.add(tmp);
        }
        return res.toArray(new String[0]);
    }
}