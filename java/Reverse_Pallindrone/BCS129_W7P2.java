import java.util.*;

class sol {

  int A;
  int B;
  char C;
  String str1;
  String str2;

  public void setn(int x) {
    A = x;
  }

  public void setm(int x) {
    B = x;
  }

  public void setc(char C) {
    this.C = C;
  }

  public void sets1(String s) {
    str1 = s;
  }

  public void sets2(String s) {
    str2 = s;
  }

  public int solution(int N, char ch) {
    if (ch == 's') {
      return N * N;
    } else {
      return N * N * N;
    }
  }

  public int solution(int N, int M, char ch) {
    if (ch == 'p') {
      return N * M;
    } else {
      return N + M;
    }
  }

  public boolean solution(String x, String y) {
    if (x.equals(y)) return true; else {
      return false;
    }
  }
}

public class BCS129_W7P2 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("enter values of A and B");
    int A = sc.nextInt();
    int B = sc.nextInt();
    System.out.println("entr the character");
    char C = sc.next().charAt(0);
    System.out.println("enter str1");
    String x = sc.next();
    System.out.println("enter str2");
    String y = sc.next();

    sol obj = new sol();
    obj.setn(A);
    obj.setm(B);
    obj.setc(C);
    obj.sets1(x);
    obj.sets2(y);

    int ans1 = obj.solution(A, C);
    int ans2 = obj.solution(A, B, C);
    boolean ans3 = obj.solution(x, y);
    System.out.println(ans1);
    System.out.println(ans2);
    System.out.println(ans3);
  }
}
