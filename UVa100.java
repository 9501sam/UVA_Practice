import java.util.Scanner;

public class UVa100{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()){
			//read i and j
			int i = sc.nextInt();
			int j = sc.nextInt();
			System.out.print(i + " " + j + " ");
			if(i > j){
				int t = i;
				i = j;
				j = t;
			}

			//find cycle-length betweeen i to j
			int maxLength = 0;
			for(int k = i; k <= j; k++){
				//find cycle-length of k
				int n = k;
				int count = 1; //n itself
				while(n != 1){
					if(n % 2 == 1){
						n = 3 * n + 1;
					}else{
						n = n / 2;
					}
					count++;
				}

				if(count > maxLength){
					maxLength = count;
				}
			}

			//print
			System.out.println(maxLength);
		}
	}
}
