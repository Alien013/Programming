import java.util.Scanner;
class Method1
{
    // static int Add(int x,int y) {
    static int Add(int ...arr) {
        int sum=0;
        for(int a:arr) {
            sum+=a;
        }
        return sum;
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        // int n1=sc.nextInt();       
        // int n2=sc.nextInt();       
        // int sum=Add(n1,n2);
        System.out.println("Addition of 1 & 2 is "+Add(1,2));
        System.out.println("Addition of 1 & 2 & 3 is "+Add(1,2,3));
        System.out.println("Addition of 1 & 2 & 3 & 4 is "+Add(1,2,3,4));
        sc.close();
    }
}