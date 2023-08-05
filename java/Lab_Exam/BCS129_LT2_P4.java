import java.util.*;

abstract class Person {

  abstract void Student(String name);
}

class Student extends Person {

  String name;
  String address;
  String phone;
  String email;

  void Student(String name, String address, String phone, String email) {
    this.name = name;
    this.address = address;
    this.phone = phone;
    this.email = email;
  }

  void to_string() {
    System.out.println("Name: " + name);
    System.out.println("address: " + address);
    System.out.println("phone: " + phone);
    System.out.println("email: " + email);
  }
}

class BCS129_LT2_P4 {

  public static void main(String[] args) {
    Scanner sc1 = new Scanner(System.in);
    Scanner sc2 = new Scanner(System.in);
    int choice = sc1.nextInt();
    String name = sc2.nextLine();
    String address = sc2.nextLine();
    String phone = sc2.nextLine();
    String email = sc2.nextLine();
    switch (choice) {
      case 1:
        {
          Student pt = new Student();
          pt.Student(name);
          pt.Student(address);
          pt.Student(phone);
          pt.Student(email);
          pt.to_string();
          break;
        }
    }
    sc1.close();
  }
}
