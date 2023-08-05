import java.util.Scanner;
class Upper_To_Lower
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the string");
    String s1=sc.nextLine();    
    for(int i=0;i<s1.length();i++) {
        if((Character..isUppperCase(s1.charAt(i))) == true)
        System.out.println((Character.toLowerCase(s1.charAt(i))));
        else if((Character..isLowerCase(s1.charAt(i))) == true)
        System.out.println((Character.toUpperCase(s1.charAt(i))));
        else
        System.out.println(s1.charAt(i));
    }
    sc.close();
    }
}


