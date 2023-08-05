import java.util.Scanner;

class Right_shift_array {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr1 = new int[n];

    for (int i = 0; i < n; i++) {
      arr1[i] = sc.nextInt();
    }
    int shift = sc.nextInt();
    System.out.println(" Original Array");

    for (int i = 0; i < arr1.length; i++) {
      System.out.print(arr1[i] + " ");
    }

     for(int i = 0; i < shift; i++){    
            int j, last;    
            last = arr1[arr1.length-1];    
            
            for(j = arr1.length-1; j > 0; j--){    
                arr1[j] = arr1[j-1];    
            }    
            arr1[0] = last;    
        }    
        
        System.out.println();    
            
        System.out.println("Array after right rotation: ");    
        for(int i = 0; i< arr1.length; i++){    
            System.out.print(arr1[i] + " ");    
        }    

    sc.close();
  }
}
