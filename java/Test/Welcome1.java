import java.util.Scanner;

public class Welcome1 {
    public static void main(String[] ar) {
        Scanner input = new Scanner(System.in);
        int a, b, c;
        a = input.nextInt();
        b = input.nextInt();
        c = input.nextInt();

        System.out.printf("%d\n%d\n%d\n%d\n", (a + b) % c, ((a % c) + (b % c)) % c,
                                 (a * b) % c, ((a % c) * (b % c)) % c);
    }
}
