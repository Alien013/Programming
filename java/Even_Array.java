import java.util.*;

class Even_Array {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int i, j;
    int[] arr = new int[n];
    System.out.println("Enter the Elements");
    for (i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    System.out.println("Odd Array");
    for (j = 0; j < n; j++) {
      if (arr[j]%2 == 0) {
        System.out.print(arr[j]+" ");
      }
    }
    
    System.out.println();

    System.out.println("Even Array");
    for (j = 0; j < n; j++) {
      if (arr[j]%2 != 0) {
        System.out.print(arr[j]+" ");
      }
    }
    sc.close();
  }
}
