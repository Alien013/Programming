import java.util.Scanner;
class Multiplication
{
    static void Multiplication(int n) {
        for(int i=1;i<=10;i++) {
            System.out.printf("%d x %d = %d \n",n,i,n*i);
        }
    }
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number: ");
    int num=sc.nextInt();
    Multiplication(num);
        sc.close();
    }
}