import java.util.Scanner;

public class GetFactorial {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, factorial = 1, i = 1;

        System.out.print("Enter value for n: ");
        n = scanner.nextInt();

        while (i <= n) {
            factorial *= i;
            i++;
        }

        System.out.println("Factorial: " + factorial);
        scanner.close();
    }
}
