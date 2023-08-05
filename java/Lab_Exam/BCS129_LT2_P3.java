import java.util.*;

abstract class Sports {

  String name;
  int n;

  abstract void display();
}

class get_name extends Sports {

  get_name(String name) {
    this.name = name;
  }

  //   get_number_of_players(int n) {
  //     this.n = n;
  //   }

  void display() {
    System.out.println(name);
    System.out.println("Each team has 11 player in" + name);
  }
}

class BCS129_LT2_P3 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String name = sc.nextLine();
    String N = sc.nextLine();
    get_name solution = new get_name(name);
    // get_number_of_players solution = new get_number_of_players(N);
    solution.display();
    sc.close();
  }
}
