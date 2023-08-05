import java.util.Scanner;

class Average {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int sum = 0;
    double avg;
    int n = sc.nextInt();
    int[] num = new int[n];
    for (int i = 0; i < n; i++) {
      num[i] = sc.nextInt();
    }
    for (int j : num) {
      sum += j;
    }
    int length = num.length;
    avg = ((double) sum / (double) length);
    System.out.println("sum =" + sum);
    System.out.println("average =" + avg);

    sc.close();
  }
}
