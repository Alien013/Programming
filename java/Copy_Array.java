import java.util.*;

class Copy_Array {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr1 = new int[n];
    int[] arr2 = new int[arr1.length];

    for (int i = 0; i < n; i++) {
      arr1[i] = sc.nextInt();
    }

    for (int i = 0; i < arr1.length; i++) {
      arr2[i] = arr1[i];
    }

    for (int i = 0; i < arr1.length; i++) {
      System.out.print(arr1[i] + " ");
    }
    System.out.println();
    for (int i = 0; i < arr2.length; i++) {
      System.out.print(arr2[i] + " ");
    }
    sc.close();
  }
}
