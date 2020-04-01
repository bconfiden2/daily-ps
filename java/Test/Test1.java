import java.util.Scanner;

public class Test1 {
    public static void main(String[] ar) {
        Scanner input = new Scanner(System.in);

        int x,y,z;

        System.out.printf("Input 3 Integer : ");
        x = input.nextInt();
        y = input.nextInt();
        z = input.nextInt();

        int result = x + y + z;

        System.out.printf("%d\n", result);
    }
}
