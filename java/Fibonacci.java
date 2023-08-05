import java.util.Scanner;
class Fibonacci
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    int n1=0,n2=1,n3;
    System.out.print(n1+" "+n2);
    for(int i=2;i<n;i++) {
        n3=n1+n2; 
        System.out.print(" "+n3);

        n1=n2;
        n2=n3;
    }
    sc.close();
    }
}

// class Fibonacci{
// printFibonacci(int n) {
//     if(n>0) {
//         n3=n1+n2;
//         n1=n2;
//         n2=n3;
//         System.out.print(" "+n3);
//         printFibonacci(n-1);
//     }
// }
// public static void main(String args[])
// {
//     Scanner sc = new Scanner(System.in);
//     int n=sc.nextInt();
//     int n1=0,n2=1,n3;
//     System.out.print(n1+" "+n2);
//     printFibonacci(n-2)
// }
// }