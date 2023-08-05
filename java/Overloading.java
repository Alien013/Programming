import java.util.Scanner;

class Overloading // Methd over loading is the process to call function of same name but different arguments 
{
    static void foo() {
        System.out.println("Good Morning bro");
    }
    static void foo(int a) {
        System.out.println("Good norning " + a +" bro");
    } 

    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    foo();
    foo(1000);
    }
}