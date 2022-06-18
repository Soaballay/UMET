/* 
Algoritmo de Josefo con una cola.
Cada pase es un dequeue seguida de un enqueue.
*/ 

import java.util.LinkedList;
import java.util.Queue;
import java.util.Iterator;

public class Josefo {
    public static void josephus(int personas, int pases){
        Queue<Integer> cola = new LinkedList<Integer>();		
        
        for (int i=1; i<=personas; i++) 			// Carga people en cola
        cola.add(i);
        
        Iterator <Integer> it = cola.iterator();			
        
        while(cola.size()>1){				// Pasa la papa y elimina hasta que quede 1
            for(int i=0; i<=pases;i++){
                if (!it.hasNext())
                    it = cola.iterator();
                    
                it.next();
            }  
            it.remove();
        }
        System.out.print(cola);			// Imprime el ganador
    }
    
    public static void main (String[]args){
        josephus(3, 3);
    }
}