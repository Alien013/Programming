import java.util.Scanner;

class BCS129_LABTEST_P2 {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Do you have any children");
    char first = sc.nextLine().charAt(0);
    System.out.println("Do you have lots of money");
    char second = sc.nextLine().charAt(0);
    System.out.println("Do you like trucks");
    char third = sc.nextLine().charAt(0);
    if (first == 'Y' && second == 'Y' && third == 'N') {
      System.out.println("Villager");
    } else if (first == 'N' && second == 'Y' && third == 'N') {
      System.out.println("Porsche");
    } else if (first == 'N' && second == 'N') {
      System.out.println("civic");
    } else if (first == 'Y' && second == 'Y' && third == 'Y') {
      System.out.println("Explorer");
    } else if (first == 'Y' && second == 'Y' && third == 'Y') {
      System.out.println("sentra");
    }
    sc.close();
  }
}
