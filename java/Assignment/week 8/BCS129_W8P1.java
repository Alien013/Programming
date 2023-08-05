import java.util.*;

class Base {

  int num;

  void display() {
    System.out.println("Base Calling Num is:" + num);
  }
}

class Solution extends Base {

  void solution(int N) {
    num = N;
  }
}

class BCS129_W8P1 {

  public static void main(String args[]) {
    Solution s = new Solution();
    Scanner sc = new Scanner(System.in);
    System.out.println("ENTER THE NUMBER : ");
    int N = sc.nextInt();

    s.solution(N);
    s.display();
  }
}
