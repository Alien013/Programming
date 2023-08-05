import java.util.Scanner;
class Ascending_Array
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    int temp=0;
    int[] arr = new int[n];
    System.out.println("Enter the Elements");
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    
    for(int i=0;i<arr.length;i++) {
        for(int j=i+1;j<arr.length;j++) {
            if(arr[i]>arr[j]) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
    }

    System.out.println();
    System.out.println("Ascending sorted Array");
    for(int i=0;i<arr.length;i++) {
        System.out.print(arr[i]+" ");
    }
    
    for(int i=0;i<arr.length;i++) {
        for(int j=i+1;j<arr.length;j++) {
            if(arr[i]<arr[j]) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
    }

    System.out.println();
    System.out.println("Descending sorted Array");
    for(int i=0;i<arr.length;i++) {
        System.out.print(arr[i]+" ");
    }
    sc.close();
    }
}