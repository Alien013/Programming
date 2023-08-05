import java.util.Scanner;
class Pattern_15 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int n=sc.nextInt();
        int mid=(n+1)/2;

        for(int i=1;i<=mid;i++) {
            for(int j=1;j<=mid-i;j++) {
                System.out.print(" ");
            }
            for(int k=1;k<=i*2-1;k++) {
                System.out.print("*");
            }
            System.out.println();
        }


        for(int i=1;i<=mid-1;i++) {
            for(int j=1;j<=i;j++) {
                System.out.print(" ");
            }
            for(int k=1;k<=2*(mid-i)-1;k++) {
                System.out.print("*");
            }
            System.out.println();
        }      

    //     int i,j,space=1;
    //     int n=sc.nextInt();
    //     space = n - 1;  
    // for (j = 1; j<= n; j++) {  
    //     for (i = 1; i<= space; i++) {  
    //     System.out.print(" ");  
    //     }  
    //     space--;  
    //     for (i = 1; i <= 2 * j - 1; i++) {  
    //         System.out.print("*");  
    //     }  
    //     System.out.println("");  
    // }  
    // space = 1;  
    // for (j = 1; j<= n - 1; j++) {  
    //     for (i = 1; i<= space; i++) {  
    //         System.out.print(" ");  
    //     }  
    //     space++;  
    //     for (i = 1; i<= 2 * (n - j) - 1; i++) {  
    //         System.out.print("*");  
    //     }  
    //     System.out.println("");  
    // }  
    sc.close();
    }
}