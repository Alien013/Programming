import java.util.Scanner;

class BCS129_W8P2 {

  static int Add(int x, int y) {
    int sum = 0;
      sum =x+y;
    return sum;
  }
  static void Perimeter(int x, int y) {
    int perimeter = 0;
      perimeter =2*(x+y);
    System.out.println("Perimeter of rectangle  is " + perimeter);
  }

  static int Difference(int x, int y) {
    int Diff = 0;
    
      Diff = x-y;
    return Diff;
  }

  static int Multiply(int x, int y) {
    int Product = 0;
      Product = x*y;
    return Product;
  }
  static void Area(int x, int y) {
    int area = 0;
      area = x*y;
    System.out.println("Area  of recctangle is " + area);
  }

  static int Divide(int x, int y) {
    int Div = 0;
      Div = x/y;
    return Div;
  }

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n1 = sc.nextInt();
    int n2 = sc.nextInt();
    int sum = Add(n1, n2);
    Area(n1,n2);
    Perimeter(n1,n2);
    System.out.println("Addition of n1 & n2  is " + Add(n1, n2));
    System.out.println("Difference of n1 & n2  is " + Difference(n1, n2));
    System.out.println("Product of n1 & n2  is " + Multiply(n1, n2));
    System.out.println("Divisor of n1 & n2 is " + Divide(n1, n2));
  }
}
