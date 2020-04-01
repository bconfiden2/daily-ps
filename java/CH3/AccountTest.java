import java.util.Scanner;

public class AccountTest
{
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);

    Account account1 = new Account("KSH", 30.0);
    Account account2 = new Account("ddd", -7.0);

    System.out.printf("%s balance : %3.2f\n", account1.GetName(), account1.GetBalance());
    System.out.printf("%s balance : %3.2f%n", account2.GetName(), account2.GetBalance());
  }
}
