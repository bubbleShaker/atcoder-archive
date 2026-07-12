import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer f[] = new Integer[n+1];
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            f[i]=f[i-1]*i;
        }
        System.out.println(f[n]);
    }
}