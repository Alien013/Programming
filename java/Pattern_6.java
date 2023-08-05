import java.util.Scanner;
class Pattern_6
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    for(int i=1;i<=n;i+=2) {
        for(int j=i;j>=1;j-=2) {
            System.out.print(j+" ");
        }
        System.out.println();
    }    
    sc.close();
    }
}   