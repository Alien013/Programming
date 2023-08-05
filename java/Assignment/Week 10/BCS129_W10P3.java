import java.util.Scanner;

interface Animal {
  void eat();
}

interface Mammal {
  void breathe();
}

interface WingedAnimal {
  void flap();
}

class Bat implements Animal, Mammal, WingedAnimal {

  public void eat() {
    System.out.println("Bat can eat.");
  }

  public void breathe() {
    System.out.println("Bat can breathe.");
  }

  public void flap() {
    System.out.println("Bat can flap.");
  }
}

class BCS129_W10P3 {

  public static void main(String args[]) {
    Bat animal = new Bat();
    animal.eat();
    // Mammal mammal = new Bat();
    animal.breathe();
    // WingedAnimal wingedAnimal = new Bat();
    animal.flap();
  }
}
