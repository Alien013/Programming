import java.util.Scanner;
class BCS129_LABTEST_P3
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    int count,rem;
        count=1;
    for(int i=n;i>0;i=i/10) {
        rem=n%10;
    if(rem==0)
    count=count*rem;
    }
    if(count==n)
    System.out.println("False");
    else
    System.out.println("True");
    sc.close();
    }
}