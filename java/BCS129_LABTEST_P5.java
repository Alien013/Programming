import java.util.Scanner;
class BCS129_LABTEST_P5
{
    public static void main(String args[])
    {
    
    Scanner sc = new Scanner(System.in);
    int temp,sum=0;
    int n=sc.nextInt();
    int[] points=new int[n];
    System.out.println("Enter the Elements");
    
    for (int i = 0; i < n; i++) {
      points[i] = sc.nextInt();
    }
    System.out.println("Points are:");
    for (int i = 0; i < n; i++) {
      System.out.print(points[i]+" ");
    }
    // for (int i = 0; i < n; i++) {
    //   if(points[i]<0) {
    //     temp=points.indexof(points[i]);
    //   }
    // }


    sc.close();
    }
}