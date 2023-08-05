import java.util.Scanner;
class Pallindrone
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int sum=0;
    int num=sc.nextInt();
    for(int i=num;i>0;i/=10) {
        sum=sum*10+(i%10);
    }
    if(sum==num)
    System.out.println("Pallindrone Number");
    else
    System.out.println("Not Pallindrone Number");
    sc.close();
    }
}