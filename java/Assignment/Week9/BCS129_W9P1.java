import java.util.*;

abstract class Book {

  String name, aut;
  int pr;

  abstract void display();
}

class Mybook extends Book {

  Mybook(String name, String aut, int pr) {
    this.name = name;
    this.aut = aut;
    this.pr = pr;
  }

  void display() {
    System.out.println("Title: " + name);
    System.out.println("Author: " + aut);
    System.out.println("Price: " + pr);
  }
}------------------------------








class BCS129_W9P1 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String name = sc.nextLine();
    String aut = sc.nextLine();
    int pr = sc.nextInt();
    Mybook solution = new Mybook(name, aut, pr);
    solution.display();
    sc.close();
  }
}
