import java.util.Scanner;
class  String_1
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    String str1,str2=" ";
    str1=sc.nextLine();
    for(int i=0;i<str1.length();i++) {
        if(str1.charAt(i) != ' ') {
            str2+=str1.charAt(i);
        }
        System.out.println(str2);
    }
    str2=" ";
    sc.close();
    }
}