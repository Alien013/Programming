import java.util.Scanner;
class Pattern_11
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    for(int i=1;i<=n;i+=2) {
        for(int j=i;j<=n;j+=2) {
            System.out.print(j+" ");
        }
        for(int k=1;k<i;k+=2) {
            System.out.print(k+" ");
        }
        System.out.println();
    }
    sc.close();
    }
}