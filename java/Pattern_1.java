import java.util.Scanner;
class Pattern_1
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    int a=1;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            System.out.print(a+" ");
            a++;
        }
        System.out.println();
    }
    sc.close();
        
    }
}