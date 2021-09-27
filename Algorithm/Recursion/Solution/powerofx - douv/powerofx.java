import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();

        System.out.println(pow(x, y));
    }

    private static int pow(int x, int y) {
        if (y == 1) {
            return x;
        }

        return x * pow(x, y - 1);
    }
}