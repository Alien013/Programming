import java.util.Scanner;
class Reverse_Array
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr1 = new int[n];

    for (int i = 0; i < n; i++) {
      arr1[i] = sc.nextInt();
    }
    System.out.println("Original Array");

    for(int i=0;i<arr1.length;i++) {
        System.out.print(arr1[i]+" ");
    }
    System.out.println();
    System.out.println("After Reversing Array");
    for(int i=arr1.length-1;i>=0;i--) {
        System.out.print(arr1[i]+" ");
    }
    sc.close();
    }
}