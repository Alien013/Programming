import java.util.Scanner;

class Print_3D_Array {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int m = sc.nextInt();
    int n = sc.nextInt();
    int l = sc.nextInt();
    int[][][] arr = new int[m][n][l];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < l; k++) {
          arr[i][j][k] = sc.nextInt();
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          System.out.println(arr[i][j][k] + " ");
        }
      }
    }

    sc.close();
  }
}
