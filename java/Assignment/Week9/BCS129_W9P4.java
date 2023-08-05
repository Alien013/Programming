import java.util.*;

abstract class Vegetable {

  abstract void setColor(String col);
}

class Potato extends Vegetable {

  String col;

  void setColor(String col) {
    this.col = col;
  }

  void to_string() {
    System.out.println("Potato " + col);
  }
}

class Tomato extends Vegetable {

  String col;

  void setColor(String col) {
    this.col = col;
  }

  void to_string() {
    System.out.println("Tomato " + col);
  }
}

class Eggplant extends Vegetable {

  String col;

  void setColor(String col) {
    this.col = col;
  }

  void to_string() {
    System.out.println("Eggplant " + col);
  }
}

class BCS129_W9P4 {

  public static void main(String[] args) {
    Scanner sc1 = new Scanner(System.in);
    Scanner sc2 = new Scanner(System.in);
    int choice = sc1.nextInt();
    String col = sc2.nextLine();
    switch (choice) {
      case 1:
        {
          Potato pt = new Potato();
          pt.setColor(col);
          pt.to_string();
          break;
        }
      case 2:
        {
          Eggplant eg = new Eggplant();
          eg.setColor(col);
          eg.to_string();
          break;
        }
      case 3:
        {
          Tomato tm = new Tomato();
          tm.setColor(col);
          tm.to_string();
          break;
        }
    }
    sc1.close();
  }
}
