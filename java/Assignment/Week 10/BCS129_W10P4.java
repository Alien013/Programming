import java.util.Scanner;

interface Customer {
  void SetInformations(String gen, double inc);
  void ShowInformations();
}

class Employee implements Customer {

  String gender;
  double income;

  public void SetInformations(String gen, double inc) {
    this.gender = gen;
    this.income = inc;
  }

  public void ShowInformations() {
    System.out.println(gender);
    System.out.println(income);
  }

  public double CalculateTax() {
    double taxes = 0;
    if (income <= 190000) {
      return taxes;
    } else if (income > 190000 && income <= 200000) {
      if (gender.equals("Male")) {
        taxes = income / 10;
      }
    } else if (income > 500000) {
      if (gender.equals("Male")) {
        taxes = income / 4;
      } else {
        taxes = income / 5;
      }
    } else if (income > 200000 && income <= 500000) {
      if (gender.equals("Male")) {
        taxes = income / 5;
      } else {
        taxes = income / 10;
      }
    }
    return taxes;
  }
}

class BCS129_W10P4 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String gen = sc.next();
    double inc = sc.nextDouble();
    Employee cust = new Employee();
    cust.SetInformations(gen, inc);
    cust.ShowInformations();
    System.out.print(cust.CalculateTax());
    sc.close();
  }
}
