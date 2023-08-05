import java.util.Scanner;

class Matrix_Sum {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("ENter the number of rows of array: ");
    int m = sc.nextInt();
    System.out.println("ENter the number of columns of array: ");
    int n = sc.nextInt();
    int[][] arr1 = new int[m][n];
    int[][] arr2 = new int[m][n];
    int[][] sum = new int[m][n];
    System.out.println("Enter the elements of first array: ");
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        arr1[i][j] = sc.nextInt();
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(arr1[i][j] + " ");
      }
      System.out.println(" ");
    }
    System.out.println("Enter the elements of second array: ");
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        arr2[i][j] = sc.nextInt();
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(arr2[i][j] + " ");
      }
      System.out.println(" ");
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        sum[i][j] = arr1[i][j] + arr2[i][j];
      }
      System.out.println(" ");
    }
    System.out.println("Sum of two matrices: ");
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(sum[i][j] + " ");
      }
      System.out.println(" ");
    }

    sc.close();
  }
}
