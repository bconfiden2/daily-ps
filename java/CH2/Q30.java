import java.util.Scanner;

public class Q30 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int inputNum = input.nextInt();

    if(inputNum / 100000 != 0 || inputNum / 10000 == 0)
    {
      System.out.printf("Wrong Num\n");
      return;
    }

    for(int i = 10000 ; i >= 1 ; i /= 10)
    {
      int num = (inputNum / i % 10);
      System.out.printf("%d   ", num);
    }
    System.out.printf("\n");
  }
}
