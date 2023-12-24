import java.util.Scanner;
 
public class proof {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        //int m = scan.nextInt();
        int[] arr = new int[n];
        boolean[] seen = new boolean[n+1];
        int count = 0;
        for (int i = 0; i < n ; i++){
            arr[i] = scan.nextInt();
        }
        for (int i = 0; i < n; i++){
            if(!seen[arr[i]-1])
                count++;
            seen[arr[i]] = true;
        }
        System.out.println(count);
    }
}