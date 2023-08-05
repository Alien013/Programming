import java.util.*;

interface Interest {
    int rate =25;
    double compInterest();
    double simpleInterest();
}

class BANK implements Interest{
    int pp;
    double year;
    BANK(int x,float y){
        pp=x;
        year=y;
    }


    public double compInterest(){
        return pp*Math.pow((1+rate/100.0),year)-pp;
    }

    public double simpleInterest(){

return year*pp*rate/100;
    }

}
public class BCS129_W10P1 {

    public static void main (String args[]){
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the Principal amount ");
        int P=sc.nextInt();
        System.out.println("Enter the year ");
        float T=sc.nextFloat();

        BANK bank=new BANK(P,T);
        System.out.print("simple interest = ");
        System.out.printf("%.2f" ,bank.simpleInterest());

        System.out.print("\ncompound interest = ");
        System.out.printf("%.2f" ,bank.compInterest());
    }
}