import java.util.*;

class Base {

  int num1;
  int num2;
  int Product;


  void display() {
    System.out.println("Product of number is:" + Product);
  }
}

class Solution extends Base {

  void solution(int N1,int N2) {
    Product = N1*N2;
  }
}

class BCS129_W8P3 {

  public static void main(String args[]) {
    Solution s = new Solution();
    Scanner sc = new Scanner(System.in);
    System.out.println("ENTER THE NUMBER : ");
    int N1 = sc.nextInt();
    int N2 = sc.nextInt();

    s.solution(N1,N2);
    s.display();
  }
}
