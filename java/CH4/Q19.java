import java.util.Scanner;

public class Q19
{
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    
    System.out.printf("Enter Each Item sold : \n");
    int numItem1 = input.nextInt();
    int numItem2 = input.nextInt();
    int numItem3 = input.nextInt();
    int numItem4 = input.nextInt();

    System.out.printf("Earning : %.2f $\n", 200 +
                      0.09f * (numItem1 * 239.99f + numItem2 * 129.75f + numItem3 * 99.95f + numItem4 * 350.89f));
  }
}
