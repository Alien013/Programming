import java.util.Scanner;
class Pattern_12
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    for( int i=1;i<=n;i++) {
        for(int j=i;j<=(n-1);j++) {
            System.out.print("  ");
        }
        for(int k=1;k<=i;k++) {
            System.out.print(k+" ");
        }
        for(int l=i-1;l>=1;l--) {
            System.out.print(l+" ");
        }
        System.out.println();
    }
    sc.close();
    }
}