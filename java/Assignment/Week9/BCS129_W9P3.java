import java.util.*;

abstract class Car {

  String model;
  int s;

  Car(String model, int s) {
    this.model = model;
    this.s = s;
  }
}

class Suzuki extends Car {

  Suzuki(String model, int s) {
    super(model, s);
  }

  String getModel() {
    return model;
  }

  int getMaxSpeed() {
    return s;
  }
}

class BCS129_W9P3 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String model = sc.nextLine();
    int s = sc.nextInt();
    Suzuki sol = new Suzuki(model, s);
    System.out.println(sol.getModel());
    System.out.println(sol.getMaxSpeed());

    sc.close();
  }
}
