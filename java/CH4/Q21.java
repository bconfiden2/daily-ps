import java.util.Scanner;

public class Q21
{
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);

    int counter = 0;
    int number = 0;
    int largest = 0; //number 는 팔린갯수이기 때문에 0 이상이므로 초기화를 0으로 해줘도 될거같다

    System.out.printf("put 10 integers\n");

    while(++counter <= 10)
    {
      number = input.nextInt();

      if(number > largest)
      {
        largest = number;
      }
    }

    System.out.printf("largets number : %d\n", largest);
  }
}
