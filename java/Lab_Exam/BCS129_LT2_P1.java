import java.util.Scanner;

class Employee {

  int salary;

  public int mean(int array[]) {
    int summer = 0;
    for (int i = 0; i < array.length; i++) {
      summer += array[i];
    }
    return summer / array.length;
  }

  public int median(int array[]) {
    int n = array.length;
    return array[n / 2];
  }

  public int mode(int array[]) {
    int highest = 0;
    int mode = array[0];
    for (int i = 0; i < array.length; i++) {
      int hold = 0;
      for (int j = 0; j < array.length; j++) {
        if (array[j] == array[i]) {
          ++hold;
        }
      }
      if (hold > highest) {
        highest = hold;
        mode = array[i];
      }
    }
    return mode;
  }
}

public class BCS129_LT2_P1 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int array[] = new int[n];

    for (int i = 0; i < n; i++) {
      array[i] = sc.nextInt();
    }

    Employee emp = new Employee();

    int mean = emp.mean(array);
    System.out.println("Mean of the salary : " + mean);

    System.out.println("Mode of the salary :" + emp.mode(array));

    System.out.println("Median of the salary :" + emp.median(array));

    int count = 0;
    int meancounter = 0;
    for (int i = 0; i < array.length; i++) {
      if (array[i] > mean) {
        ++count;
      } else if (array[i] == mean) {
        ++meancounter;
      }
    }

    System.out.println("Number of Employees Above Mean: " + count);

    System.out.println(
      "Number of Employees Below Mean: " + (array.length - count - meancounter)
    );

    sc.close();
  }
}
