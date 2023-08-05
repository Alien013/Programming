import java.util.*;
class Digit_Alpha_Space
{
    public static void main(String args[]) 
    {
        Scanner sc=new Scanner(System.in);
        String s1;
        int digit=0,alpha=0,space=0;
        s1=sc.nextLine();
        int l=s1.length();
        char p;
        for(int i=0;i<l;i++) {
            p=s1.charAt(i);
            if(Character.isDigit(p)) {
                digit++;
            }
            else if(Character.isLetter(p)) {
                alpha++;
            }
            else if(Character.isSpaceChar(p)){
                space++;
            }

        }
        System.out.println("Number of digits "+ digit);
        System.out.println("Number of alphabets "+ alpha);
        System.out.println("Number of Whitespaces "+ space);
        sc.close();
    }
}