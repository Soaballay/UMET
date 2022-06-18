// Imprime todas las permutaciones de los caracteres que componen el string

public class PermutarCadena_recursion {
    public static void main (String args[]){
        permute("abc");
    }

    public static void permute(String str) { 
        permutar("", str); 
    }
    
    private static void permutar(String prefijo, String str) {
        int n = str.length();
        if (n == 0) 
            System.out.println(prefijo);
        else 
        {
            for (int i = 0; i < n; i++)
                permutar(prefijo + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
        }
    }
}