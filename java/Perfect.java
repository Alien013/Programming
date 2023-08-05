import java.util.Scanner;
class Perfect
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int num=sc.nextInt();
    int count=0;
    for(int i=1;i<num;i++) {
        if(num%i==0)
        count+=i;
    }    
    if(count==num)
    System.out.println("Perfect Number");
    else
    System.out.println("Not perfect Number");
    sc.close();
    }
}