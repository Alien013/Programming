import java.util.*;

abstract class EmployeeDetails {

  private String name;
  private int E_id;

  EmployeeDetails(String name, int E_id) {
    this.name = name;
    this.E_id = E_id;
  }

  void commonEmpDetails() {
    System.out.println("Employee Name=" + name);
    System.out.println("Employee Id=" + E_id);
  }

  abstract void Details();
}

class HR extends EmployeeDetails {

  private int Sal;
  private String performance;

  HR(String name, int E_id, int Sal, String performance) {
    super(name, E_id);
    this.Sal = Sal;
    this.performance = performance;
  }

  void Details() {
    System.out.println("Salary=" + Sal);
    System.out.println("Performance=" + performance);
  }
}

class BCS129_W9P2 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Scanner sc1 = new Scanner(System.in);
    String name = sc.nextLine();
    int id = sc.nextInt();
    int Sal = sc.nextInt();
    String performance = sc1.nextLine();
    HR sol = new HR(name, id, Sal, performance);
    sol.Details();
    sol.commonEmpDetails();
    sc.close();
  }
}
