import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		
		int cnt = 0;
		while(N-- > 0) {
			int num = scan.nextInt();
			int SW = 0;
			if(num == 1) SW = 1;
			for(int i = 2; i < num; i++) {
				if(num % i == 0) SW = 1;
			}
			if(SW == 0) cnt++;
		}
		System.out.println(cnt);
	}

}


