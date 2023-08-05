import java.util.Scanner;
class Unique
{
    public static void main(String args[])
    {
        int rem1,rem2,num,num1,num2,count=0;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number");
    num = sc.nextInt();
    num1=num;
    num2=num;
    while(num1>0) {
        rem1=num1%10;
        while(num2>0) {
            rem2=num2%10;
            if(rem1==rem2)
            count++;
            num2/=10;
        }
        num1/=10;
    }
    if(count==1) 
    System.out.println("Unique Number");
    else
    System.out.println("Not Unique Number");
    sc.close();
    }
}