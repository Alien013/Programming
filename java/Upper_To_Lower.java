import java.util.*;
class Upper_To_Lower
{
    public static void main(String args[]) 
    {
        Scanner sc=new Scanner(System.in);
        // InputStreamReader isr=new InputStreamReader(System.in);
        // BufferedReader br =new BufferedReader(isr);
        String s1;
        s1=sc.nextLine();
        // s1 = br.readLine();
        int l=s1.length();
        char p;
        for(int i=0;i<l;i++) {
            p=s1.charAt(i);
            if(Character.isLowerCase(p)) {
                System.out.println(Character.toUpperCase(p));
            }
            else if(Character.isUpperCase(p)) {
                System.out.println(Character.toLowerCase(p));
            }
            else 
            System.out.println(p);

        }
        sc.close();
    }
}