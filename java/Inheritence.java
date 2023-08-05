import java.util.Scanner;

class Base {

  int x;

  public int getx() {
    return x;
  }

  public int setx(int x) {
    System.out.println("I'm setting x now");
    this.x = x;
   }
   public void Print() {
     System.out.println("I'm a constructor");
   }
}

// class Derived extends Base() {
//     int y;
//     public int gety();
//     return y;
// }

class Inheritence {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    Base b=new Base();
    b.setx(4);
    System.out.println(b.getx());
    // Derived d=new Derived();
    // b.setx(4);System.out.println(b.getx());

  }
}

// class Animal{  
// void eat(){System.out.println("eating...");}  
// }  
// class Dog extends Animal{  
// void bark(){System.out.println("barking...");}  
// }  
// class BabyDog extends Dog{  
// void weep(){System.out.println("weeping...");}  
// }  
// class TestInheritance2{  
// public static void main(String args[]){  
// BabyDog d=new BabyDog();  
// d.weep();  
// d.bark();  
// d.eat();  
// }}  