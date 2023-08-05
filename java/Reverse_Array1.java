import java.util.Scanner;

class Reverse_Array1 {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Enter the size of array: ");
    int n = sc.nextInt();
    int[] arr = new int[n];
    System.out.println("Enter the original array");
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }

    // System.out.println("\nNew array in reverse order: ");
    // for(int i=n-1;i>=0;i--) {
    //     System.out.print(arr[i] + " ");
    // }

    // int[] arr={1,2,3,4,5};
    
    int l=arr.length;
    int k = Math.floorDiv(l, 2);
    int temp;
    for(int i=0;i<k;i++) {
        temp=arr[i];
        arr[i]=arr[l-1-i];
        arr[l-1-i]=temp;
    }
    System.out.println("\nNew array in reverse order: ");
    for(int element: arr) {
        System.out.print(element + " ");
    }
    sc.close();
  }
}
