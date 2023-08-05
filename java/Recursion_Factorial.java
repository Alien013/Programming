import java.util.Scanner;

class Recursion_Factorial {

  static long Factorial(long n) {
    if (n == 0 || n == 1) {
      return 1;
    } else {
      return n * Factorial(n - 1);
    }
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    long num = sc.nextInt();
    long Fact = Factorial(num);
    System.out.println("Facorial of " + num + " is " + Fact);
    sc.close();
  }
}

