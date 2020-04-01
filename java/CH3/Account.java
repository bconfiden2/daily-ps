public class Account
{
  private String name;
  private double balance;

  public Account(String name, double balance)
  {
    this.name = name;
    if(balance > 0.0)
    {
      this.balance = balance;
    }
  }

  public void Deposit(double depositAmount)
  {
    if(depositAmount > 0.0)
    {
      balance += depositAmount;
    }
  }

  public double GetBalance()
  {
    return balance;
  }

  public void SetName(String name)
  {
    this.name = name;
  }

  public String GetName()
  {
    return name;
  }
}
