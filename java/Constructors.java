import java.util.Scanner;
class Employee{
    private int id;
    private String name;

    public Employee(){
        id=45;
        name="manoj";
    }
    // 
    public String getname() {
        return name;
    }
    public void setName(String n){
        this.name=n;
    }
    public void setId(int i){
        this.id=i;
    }
    public int getId() {
        return id;
    }
}
public class Constructors
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
    Employee emp = new Employee();

    System.out.println(emp.getId());
    System.out.println(emp.getname());
        
        sc.close();
    }
}