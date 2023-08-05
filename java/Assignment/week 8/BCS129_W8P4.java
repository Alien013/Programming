import java.util.Scanner;
class player
{
    String name,name1;
    String team,team1;
    int jersey,jersey1;
    public void inputPlayer(String Name,String t,int j)
    {
        name=Name;
        team=t;
        jersey=j;

    }
    public void inputPlayer1(String Name,String t,int j)
    {
        name1=Name;
        team1=t;
        jersey1=j;
    }
    public void OutputPlayer()
    {
        System.out.println(name);
        System.out.println(team);
        System.out.println(jersey);


    }
}
class derived2 extends player
{
    public void compare(String n,String t,int j)
    {
        if((n.equals(name))&& (t.equals(team)) && (j==jersey))
        {
            System.out.println("player Exists");
        }
        else
        {
            System.out.println("player does not Exists");
        }
    }
}
public class BCS129_W8P4 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        derived2 d= new derived2();

        System.out.println("Enter the player1 details ");
        String name=sc.nextLine();
        String team=sc.nextLine();
        int jersey=sc.nextInt();
        d.inputPlayer(name,team,jersey);
        d.OutputPlayer();        

        d.compare("Manoj","India",1);
        sc.close();
    }
}