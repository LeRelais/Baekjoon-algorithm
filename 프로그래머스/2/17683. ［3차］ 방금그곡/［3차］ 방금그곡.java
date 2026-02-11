import java.io.*;
import java.util.*;
import java.lang.*;

class DATA{
    int t;
    int idx;
    String name;
    public DATA(int t, int idx, String name){
        this.t = t;
        this.idx = idx;
        this.name = name;
    }
}

class Solution {
public String solution(String m, String[] musicinfos) {
    m = replaceSharp(m);
    PriorityQueue<DATA> pq = new PriorityQueue<>((a, b) -> {
        if (a.t == b.t) return Integer.compare(a.idx, b.idx); // 시간 같으면 먼저 입력된 순
        return Integer.compare(b.t, a.t); // 재생 시간 긴 순
    });

    for (int i = 0; i < musicinfos.length; i++) {
        String[] info = musicinfos[i].split(",");
        int t = calculateTime(info[0], info[1]);
        String title = info[2];
        String sheet = replaceSharp(info[3]);

        // 1. 재생 시간에 맞춰 실제 연주된 악보 생성
        StringBuilder played = new StringBuilder();
        for (int j = 0; j < t; j++) {
            played.append(sheet.charAt(j % sheet.length()));
        }

        // 2. 포함 여부 확인
        if (played.toString().contains(m)) {
            pq.add(new DATA(t, i, title));
        }
    }

    return pq.isEmpty() ? "(None)" : pq.peek().name;
}

private int calculateTime(String start, String end) {
    String[] s = start.split(":");
    String[] e = end.split(":");
    return (Integer.parseInt(e[0]) * 60 + Integer.parseInt(e[1])) 
         - (Integer.parseInt(s[0]) * 60 + Integer.parseInt(s[1]));
}
    public String replaceSharp(String str){
        return str.replace("C#", "c")
                  .replace("D#", "d")
            .replace("F#", "f")
            .replace("G#", "g")
            .replace("A#", "a")
            .replace("B#", "C")
            .replace("E#", "F");
    }
}