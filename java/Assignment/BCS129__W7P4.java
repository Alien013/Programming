import java.util.*;
class pathology {
  Scanner sc = new Scanner(System.in);
  String name = "", sex = "", aadhar_number = "", address = "", customer_id =
    "";
  int age;
  long mobile_number;
  char option;
  double bgt = 200, lft = 450, sugar = 600.50, kft = 800, hg = 240.5, cst = 99;
  public void show_user_AccountDetails() {
    System.out.println();
    System.out.println("Customer Id : " + customer_id);
    System.out.println("User Name : " + name);
    System.out.println("Mobile Number : " + mobile_number);
    System.out.println("Customer Address : " + address);
  }
  public void insert_blood_checkup_cost() {
    System.out.println();
    System.out.println("Blood Group Test : 200");
    System.out.println("LFT Test : 450");
    System.out.println("Sugar Test : 600.5");
    System.out.println("KFT Test : 800");
    System.out.println("Haemoglobin Test : 240.5");
    System.out.println("Cholestrol Test : 99");
    System.out.println();
    System.out.println("Which test you want: ");
    option = sc.next().charAt(0);
  }
  public double Blood_checkup_package() {
    switch (option) {
      case 'A':
        return bgt + lft + sugar;
      case 'B':
        return lft + cst + hg;
      case 'C':
        return bgt + lft + cst + hg;
      default:
        return lft + cst + hg + kft;
    }
  }
  public void display_Amount() {
    if (age > 60) {
      System.out.println("Total Cost : " + 0.75 * Blood_checkup_package());
    } else {
      System.out.println("Total Cost : " + Blood_checkup_package());
    }
  }
  void open_user_Account() {
    do {
      System.out.println("Enter name: ");
      name = "";
      name = sc.nextLine();
      if (name.equals("")) {
        System.out.println("Name required! Enter again.");
      }
    } while (name.length() == 0);
    do {
      System.out.println("Enter sex: ");
      sex = "";
      sex = sc.nextLine();
      if (sex.equals("")) {
        System.out.println(
          "Allowed values are Male, Female and Others ! Enter again."
        );
      }
    } while (
      !(
        (sex.equals("Male")) || (sex.equals("Female")) || (sex.equals("Others"))
      )
    );
    do {
      System.out.println("Enter your age: ");
      age = sc.nextInt();
      if (age < 1 || age > 100) {
        System.out.println("Allowed value are between 1 and 100! Enter again.");
      }
    } while (age < 1 || age > 100);
    Scanner sc2 = new Scanner(System.in);
    while (true) {
      System.out.println("Enter address: ");
      address = sc2.nextLine();
      if (address.length() == 0) {
        System.out.println("Address required! Enter again.");
      } else break;
    }
    boolean flag = true;
    do {
      System.out.println("Enter Mobile Number: ");
      mobile_number = sc.nextLong();
      if (mobile_number >= 6600000000L && mobile_number <= 9999999999L) {
        flag = false;
      } else {
        System.out.println(
          "Mobile number should be of 10 digits! Enter again."
        );
      }
    } while (flag);
    boolean flag1 = true;
    do {
      System.out.println("Enter Aadhar Number: ");
      aadhar_number = sc.next();
      if (aadhar_number.length() == 12) {
        flag1 = false;
      } else {
        System.out.println("Aadhar Number should be 12 digits ! Enter again.");
      }
    } while (flag1);
    customer_id += String.valueOf(48 + ((age / 10) % 10));
    customer_id += String.valueOf(48 + ((age) % 10));
    Long temp = mobile_number;
    int c = 3;
    while (c != 0) {
      customer_id += String.valueOf(temp % 10);
      temp = temp / 10;
      c--;
    }
  }
}
  class BCS129__W7P4
{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    pathology obj = new pathology();
    obj.open_user_Account();
    System.out.println();
    obj.show_user_AccountDetails();
    obj.insert_blood_checkup_cost();
    obj.Blood_checkup_package();
    obj.display_Amount();
  }
}