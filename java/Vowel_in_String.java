import java.util.Scanner;
class Vowel_in_String
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int count=0;
    String str=sc.nextLine();
    for(int i=0;i<str.length();i++) {
    if(str.charAt(i)=='A'||str.charAt(i)=='E'||str.charAt(i)=='I'||str.charAt(i)=='O'||str.charAt(i)=='U'||str.charAt(i)=='a'||str.charAt(i)=='e'||str.charAt(i)=='i'||str.charAt(i)=='o'||str.charAt(i)=='u') {
    count++;
    }
    }

    System.out.print("Total number of vowels :");
    System.out.println(count);
    sc.close();
    }
}