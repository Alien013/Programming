import java.util.Scanner;
class Separate_character
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    String s1=sc.nextLine();
    for(int i=0;i<s1.length();i++) {
        System.out.println(s1.charAt(i));
    }
    sc.close();
    }
}