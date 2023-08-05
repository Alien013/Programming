import java.util.Scanner;
class Frequency_Array
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr1 = new int[n];
    int[] freq = new int[arr1.length];

    for (int i = 0; i < n; i++) {
      arr1[i] = sc.nextInt();
    }
    int vis = -1;
    for(int i=0;i<n;i++) {
        int count=1;
        for(int j=i+1;j<arr1.length;j++) {
            if(arr1[i] == arr1[j]) {
                count++;

                freq[j] = vis;
            }
        }
        if(freq[i] != vis) {
            freq[i] = count;
        }
    }
    System.out.println("*********************");
    System.out.println("Elsements | Frequency");
    System.out.println("*********************");
    for(int i=0;i<freq.length;i++) {
        if(freq[i] != vis)
        System.out.println("      "+ arr1[i]+"   |   "+freq[i]);
    }
    System.out.println("*********************");
    sc.close();
    }
}