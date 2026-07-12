import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int f = n/16;
        int s = n%16;
        String base = "0123456789ABCDEF";
        System.out.print(base.charAt(f));
        System.out.println(base.charAt(s));
    }
}