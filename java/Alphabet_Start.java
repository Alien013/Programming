import java.util.*;
class Alphabet_Start
{
    public static void main(String args[]) 
    {
        Scanner sc=new Scanner(System.in);
        String s1,s2=" ";
        int digit=0,alpha=0,space=0;
        s1=sc.nextLine();
        int l=s1.length();
        char p;
        for(int i=0;i<l;i++) {
            p=s1.charAt(i);
            s2=s2+p;
            if(Character.isLetter(s2.charAt(0))) {
                System.out.println(s2);
            }
            else {
            continue;
            }
            s2 = " "; 
        }
        sc.close();
    }
}