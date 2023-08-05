import java.util.Scanner;
class String_length
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    String s1=sc.nextLine();
    String s2 = " ";
    for(int i=0;i<s1.length();i++) {
        if((s1.charAt(i)) != ' ') {
            s2=s2 + (s1.charAt(i));
        }
        else {
        System.out.println(s2 +" "+ s1.length());
        }
        s2=" ";
    }
    sc.close();
    }
}