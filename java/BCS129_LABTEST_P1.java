import java.util.*;
class BCS129_LABTEST_P1
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int N=sc.nextInt();
    int k=sc.nextInt();  
    int a= N+(int)(Math.log10(N&-N)/Math.log10(2)+1);
    System.out.println(a);
    }
}