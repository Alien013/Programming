import java.util.Scanner;
class TwoD_Array1
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("ENter the number of rows of array: ");
        int m=sc.nextInt();
        System.out.println("ENter the number of columns of array: ");
        int n=sc.nextInt();
        int[][] arr=new int[m][n];
        System.out.println("Enter the elements of array: ");
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                arr[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println(" ");
        }
        sc.close();

    }
}