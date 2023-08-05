import java.util.*;

public class BCS129_W7P3 {
    public static void main(String[] args) {
        calc obj1 = new calc();

        System.out.println("choose 1 or 2 ");
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();

        if (x == 1) {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            String s = sc.next();
            System.out.println(obj1.calculator(n1, n2, "/"));
        } else if (x == 2) {
            float n1 = sc.nextFloat();
            float n2 = sc.nextFloat();
            String s = sc.next();
            System.out.println(obj1.calculator(n1, n2, s));
        }
    }
}
class calc {  
    float calculator(int n, int m, String code) {
        float n1 = (float) n;
        float n2 = (float) m;
        if (code.equals("+")) {
            return n1 + n2;
        } else if (code.equals("-")) {
            return n1 - n2;
        } else if (code.equals("*")) {
            return n1 * n2;
        } else if (code.equals("/")) {
            if (n2 == 0.0) {
                return 0;
            }
            return n1 / n2;
        }
        return 1;
    }

    int calculator(float n1, float n2, String code) {
        if (code.equals("+")) {
            return (int) (n1 + n2);
        } else if (code.equals("-") ){
            return (int) (n1 - n2);
        } else if (code.equals("*")) {
            return (int) (n1 * n2);
        } else if (code.equals("/")) {
            if (n2 == 0) {
                return 0;
            }
            return (int) (n1 / n2);
        }
        return 1;
    }
}