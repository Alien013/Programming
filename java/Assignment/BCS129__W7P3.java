import java.util.*;
class BCS129_W7P3
{
    float add(int x, int y)
    {
        float sum;
        sum = x + y;
        return sum;
    }
    float substraction(int x, int y)
    {
        float difference;
        difference = x - y;
        return difference;
    }
    float product(int x, int y)  {
        float product;
        product = x * y;
        return product;
    }
    float division(int x, int y) {
        float division;
        division = x / y;
        return division;
    }
   
    public static void main(String[] args) 
    {    
     
        BCS129_W7P3 obj = new BCS129_W7P3();
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        float a = obj.add(m, n);
        System.out.println("Sum with two arguments:"+a);
        float b = obj.substraction(m, n);
        System.out.println("Difference of two arguments:"+b);
        float c = obj.product(m, n);
        System.out.println("Product of two arguments:"+c);
        float d = obj.division(m, n);
        System.out.println("Division of two arguments:"+d);
       
    }
}