// Resuelve sopa de letra leyendo los archivos del tablero y el diccionario

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class SopaDeLetras {
    public SopaDeLetras() throws IOException{
        secTablero = openFile("Ingrese la ruta de la sopa de letras" );
        secPalabra = openFile("Ingrese la ruta del diccionario de palabras a buscar");
        LeerTablero();
        LeerDiccionario();
    }
    
    public int Resolver(){
        int matches = 0;

        for (int r=0; r< filas; r++)
            for (int c=0; c<columnas; c++)
                for (int rd=-1; rd<=1; rd++)
                    for(int cd=-1; cd<=1; cd++)
                        if (rd!=0 || cd!=0)
                            matches += buscar(r,c,rd,cd);           
        return matches;
    }

    private int filas;
    private int columnas;
    private char tablero[][];
    private String [] diccionario;
    private BufferedReader secTablero;
    private BufferedReader secPalabra;
    private BufferedReader in = new
                BufferedReader(new InputStreamReader(System.in));

    private BufferedReader openFile (String message){
        String fileName = "";
        FileReader theFile;
        BufferedReader fileIn = null;

        do{
            System.out.println(message + ": ");
            
            try{
                fileName = in.readLine();
                if (fileName == null)
                    System.exit(0);
                theFile = new FileReader(fileName);
                fileIn = new BufferedReader(theFile);
            } catch (IOException e){
                System.err.println("No se puede acceder a " + fileName);
            }
        } while (fileIn == null);

        System.out.println("Se accedió al archivo " + fileName);
        return fileIn;
    }

    private void LeerDiccionario() throws IOException{
        List<String> palabras = new ArrayList<String>();

        String ultPalabra = null;
        String palabra;

        while ((palabra = secPalabra.readLine()) != null){
            if(ultPalabra != null && palabra.compareTo(ultPalabra) < 0){
                System.err.println("El diccionario no está ordenado");
                continue;
            }
            palabras.add(palabra);
            ultPalabra = palabra;
        }
        diccionario = new String[palabras.size()];
        diccionario = palabras.toArray(diccionario);
    }

    private void LeerTablero() throws IOException{
        String unaLinea;
        List<String> lineas = new ArrayList<String>();

        if ((unaLinea = secTablero.readLine()) == null)
        throw new IOException("La sopa de letra contiene líneas");

        columnas = unaLinea.length();
        lineas.add(unaLinea);

        while((unaLinea = secTablero.readLine()) != null){
            if (unaLinea.length() != columnas)
                System.err.println("La sopa de letra no es rectangular");
            else
                lineas.add(unaLinea);
        }

        filas = lineas.size();
        tablero = new char [filas][columnas];

        int r = 0;
        for (String laLinea : lineas)
            tablero[r++] = laLinea.toCharArray();
    }

    private int buscar (int BaseFila, int BaseCol, int FilaD, int ColD){
        String SecuenciaLetras = "";
        int numMatches = 0;
        int resultado;

        SecuenciaLetras += tablero[BaseFila][BaseCol];

        for (int i=BaseFila+FilaD, j=BaseCol+ColD; i>= 0 && j>=0 && i<filas && j<columnas; i+=FilaD, j+=ColD){
            SecuenciaLetras += tablero[i][j];
            resultado = BuscarPrefijo(diccionario, SecuenciaLetras);

            if (resultado == diccionario.length)
                break;
                
            if (!diccionario[resultado].startsWith(SecuenciaLetras))
                break;
            
            if(diccionario[resultado].equals(SecuenciaLetras)){
                numMatches ++;
                System.out.println("Se encontró " + SecuenciaLetras + " desde la posición (" + BaseFila + ";" + BaseCol + ") a la posición (" + i + ";" + j + ")");
            }
        }
        return numMatches;
    }

    private static int BuscarPrefijo(String[ ]a, String x){
        int idx = Arrays.binarySearch(a,x);

        if(idx<0)
            return -idx -1;
        else 
            return idx;
        
    }

    public static void main (String[]args){
        SopaDeLetras p = null;

        try{
            p = new SopaDeLetras();
        }catch (IOException e){
            System.out.println("IO Error: ");
            e.printStackTrace();
            return;
        }

        System.out.println("Buscando... ");
        p.Resolver();
    }
}