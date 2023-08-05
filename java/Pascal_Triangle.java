import java.util.Scanner;
class Pascal_Triangle
{
    public static void printPascal(int n)
    {
        for (int line = 1; line <= n; line++) {
            for (int j = 0; j <= n - line; j++) {
                System.out.print(" ");
            }
 
            int C = 1;
            for (int i = 1; i <= line; i++) {
 
                System.out.print(C + " ");
                C = C * (line - i) / i;
            }
            System.out.println();
        }
    }
    //  static int factorial(int n) {
    //     int f;
    //     for( f = 1; n > 1; n--){
    //     f *= n;
    //     }
    //     return f;
    // }

    // static int ncr(int n,int r) {
    //     return factorial(n) / ( factorial(n-r) * factorial(r) );
    // }
    
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    System.out.println();
    int n, i, j;

    n=sc.nextInt();
    printPascal(n);

    // for(i = 0; i <= n; i++) {
    //      for(j = 0; j <= n-i; j++){
    //         System.out.print(" ");
    //      }
    //      for(j = 0; j <= i; j++){
    //         System.out.print(" "+ncr(i, j));
    //      }
    //      System.out.println();
    //   }
    sc.close();
    }
}