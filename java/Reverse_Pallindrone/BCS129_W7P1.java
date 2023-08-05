import java.util.*;

class multifunc {
    String s;
    public boolean Check_pal(String s) {
        int c = 0;
        for (int i = 0; i < (s.length()) / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                c++;
                break;
            }
        }
        if (c == 0)
            return true;
        else
            return false;
    }

    public String reversesymbols(String s) {
        char arr[]=new char[10];
        int ind=0;
        for(int j=0;j<s.length();j++){
            if(s.charAt(j) == '+' || s.charAt(j) == '/' || s.charAt(j) == '*' || s.charAt(j) == '=' || s.charAt(j) == '-' || s.charAt(j) == '<' || s.charAt(j) == '>' || s.charAt(j) == '^'){
                    arr[ind]=s.charAt(j);
                    ind++;
            }
        }
        ind--;
        char str[]=new char[s.length()];
        int k=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '+' || s.charAt(i) == '/' || s.charAt(i) == '*' || s.charAt(i) == '=' || s.charAt(i) == '-' || s.charAt(i) == '<' || s.charAt(i) == '>' || s.charAt(i) == '^'){
                    str[k]=arr[ind--];
            }
            else{
                str[k]=s.charAt(i);
            }
            k++;
        }
        String string = new String(str);

        return string;
    }

    public boolean Check_pattern(String s) {
        int count = 0;
        int i = 0;
        while (s.charAt(i) != 'n') {
            count++;
            i++;
        }
        while (i != s.length() ) {
            if (s.charAt(i) == 'n')
                count--;
            else
                return false;
            i++;
        }
        if (count == 0)
            return true;
        else
            return false;

    }
}

class BCS129_W7P1 {
    public static void main(String args[]) {
        multifunc F = new multifunc();
        System.out.println("choose 1 or 2 or 3");
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();

        String s = sc.next();
        if (x == 1)
            F.Check_pal(s);
        else if (x == 2)
            System.out.println(F.reversesymbols(s));
        else if (x == 3)
            System.out.println(F.Check_pattern(s));
    }

}