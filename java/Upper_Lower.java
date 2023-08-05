import java.util.*;
class Upper_Lower
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int upper=0,lower=0,space=0,i;

    String str=sc.nextLine();
    for(i=0;i<str.length();i++) {
        int p=str.charAt(i);
        if(Character.isUpperCase(p) == true)
        upper++;
        if(Character.isLowerCase(p) == true)
        lower++;
        if((p==' ') == true)
        space++;
    }
    System.out.println("Uppercase characters="+ upper);
    System.out.println("Lowercase characters="+ lower);
    System.out.println("Whitespace characters="+ space);
    sc.close();
        
    }
}