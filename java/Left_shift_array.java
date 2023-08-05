import java.util.Scanner;

class Left_shift_array {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr1 = new int[n];
    // int[] arr2 = new int[arr1.length];

    for (int i = 0; i < n; i++) {
      arr1[i] = sc.nextInt();
    }
    int shift = sc.nextInt();
    System.out.println(" Original Array");

    for (int i = 0; i < arr1.length; i++) {
      System.out.print(arr1[i] + " ");
    }

    for (int i = 0; i < shift; i++) {
      int j,first; 
      first = arr1[0];

      for ( j = 0; j < arr1.length -1; j++) {
        arr1[j] = arr1[j + 1];
      }
      arr1[j] = first;
    }
    System.out.println();

    System.out.println("After shifting Array");
    for (int i = 0; i < arr1.length; i++) {
      System.out.print(arr1[i] + " ");
    }
    sc.close();
  }
}
