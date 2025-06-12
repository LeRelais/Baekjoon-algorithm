import java.util.*;

import java.lang.*;

import java.io.*;

 

public class Main

{

public static void main (String[] args) throws java.lang.Exception

{

Queue<Integer> q = new LinkedList<>();

Scanner sc = new Scanner(System.in);

int a = sc.nextInt();

for(int i = 1; i <= a; i++){

q.add(i);

}

while(true){

if(q.size() == 1) break;

q.poll();

q.add(q.poll());

}

System.out.println(q.poll());

}
}