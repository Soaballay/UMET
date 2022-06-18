// Calcula máximo común divisor con recursión

public class Gcd_recursion{
    public static void main(String[] args){
        gcd(1995,1494);
    }
    
    static void gcd(int a, int b){
        if (b == 0)
            System.out.print(a);
        else
            gcd(b,a%b);
    }
}