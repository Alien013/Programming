import java.util.*;

class Array_1 {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int i, j;
    String[] name = new String[n];
    int[] age = new int[n];
    for (i = 0; i < n; i++) {
      System.out.println("Enter the names");
      name[i] = sc.next();
    }
    for (i = 0; i < n; i++) {
      System.out.println("Enter the age");
      age[i] = sc.nextInt();
    }
    for (j = 0; j < n; j++) {
      if (age[j] >= 18 && age[j] <= 40) {
        System.out.print(name[j] + " " + age[j] + " ");
      }
    }
    sc.close();
  }
}
