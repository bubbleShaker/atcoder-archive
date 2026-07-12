import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        b*=1000;
        double ans = b/a;
        ans/=1000;
        System.out.println(String.format("%.3f",ans));
    }
}