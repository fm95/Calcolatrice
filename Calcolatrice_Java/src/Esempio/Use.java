package Esempio;

import java.util.ArrayList;

import vertice.*;
import PoligoniConvessi.*;
import Eccezioni.*;

public final class Use {

	// Usage example of the hierarchy
	
	public static void main(String[] args) {

	    Punto p1 = new Punto(1, 1);
	    Punto q2 = new Punto(1, 10);
	    Punto p2 = new Punto(1, 5);
	    Punto p3 = new Punto(5, 5);
	    Punto q3 = new Punto(5, 10);
	    Punto p4 = new Punto(5, 1);
	    
	    // PUNTO
	    System.out.println("Test Punto:");
	    System.out.println(p1);
	    System.out.println("Determinante: " + Punto.determinante(p1, q3));
	    System.out.println("Distanza: " + Punto.distanza(p1, p2));

	    Vertice v1 = new Vertice(p1, 1);
	    Vertice v2 = new Vertice(p2, 2);
	    Vertice v3 = new Vertice(p3, 3);
	    Vertice v4 = new Vertice(p4, 4);
	    Vertice e = new Vertice(new Punto(10,10));
	    
	    // VERTICE
	    System.out.println("\nTest Vertice:");
	    System.out.println(v1);
	    System.out.println("Angolo vertici: " + Vertice.AngoloVertici(v1, v3, v4));

	    ArrayList<Vertice> v = new ArrayList<Vertice>();
	        v.add(v1); v.add(v2); v.add(v3); 
	        
	    try
	    {
    	// TRIANGOLO
	    	System.out.println("\nTest Triangolo:");
	    	
	    	Triangolo t = new Triangolo("test_tr", v);
	        System.out.println(t);
	        System.out.println("Perimetro: " + t.getPerimetro());
	        System.out.println("Area: " + t.getArea());
	        System.out.println("Regolare? " + t.isRegolare());
	        System.out.println("Rettangolo? " + t.isRettangolo());
//	        System.err.println(t.getApotema()); // Exception: il triangolo non e' regolare
	    	
	        Triangolo t2 = (Triangolo) t.clone();
	        System.out.println(t.equals(t2 + "\n"));
	        
        // QUADRILATERO
	        System.out.println("\nTest Quadrilatero:");
	        
	        Quadrilatero q4 = (Quadrilatero) t2.inserisciVertice("Quadri", v4);
	        System.out.println(q4);
	        System.out.println("Area: " + q4.getArea());
	        q4.modificaInfo(1, 3.5);
//	        q4.modificaInfo(10, 3.5); // Exception: posizione troppo grande
	        System.out.println(q4); // con info modificato
	        System.out.println("Equilatero? " + q4.isEquilatero());
	        System.out.println("Media info: " + q4.AVG());
	        System.out.println("Max info: " + q4.Max());
	        System.out.println("Angolo vertice con info=3 : " + q4.getAngolo(3, -1)); // non passo la posizione
//	        System.err.println(q4.getAngolo(3, 4)); // Exception: posizione >= Vertici.size
	        System.out.println("Lato tra il vertice con info=1 e vertice successivo: " + q4.getLato(1, -1));
	       
        // RETTANGOLO
	        System.out.println("\nTest Rettangolo:");
	        
	        ArrayList<Vertice> arr2 = new ArrayList<Vertice>();
	        arr2.add(v1); arr2.add(v2); arr2.add(v3); arr2.add(v4);
	        
        	Rettangolo ret = new Rettangolo("RRR", arr2);
        	System.out.println(ret);
        	System.out.println(ret.getAngolo(1, 0)); // info=1 & pos=0
        	System.out.println(ret.getDiagolale(0, 2)); // tra il primo e il terzo vertice
//        	System.out.println(ret.getDiagolale(0, 1)); // Eccezione: posizioni non valide
        	ret.setNome("Ciao");
        	System.out.println(ret);
        	System.out.println(ret.getArea());
	        	
    	// QUADRATO
        	System.out.println("\nTest Quadrato:");
        	
        	Quadrato q = (Quadrato) t.inserisciVertice("paolotti", v4);
        	System.out.println(q);
        	System.out.println("Apotema: " + q.getApotema());
        	System.out.println("Somma: " + q.Somma());
        	System.out.println("Sottrazione: " + q.Sottrazione());
        	System.out.println("Diagonale: " + q.getDiagolale(1, 3));
        	System.out.println("Regolare? " + q.isRegolare());
    	
    	// Elimina vertice
        	System.out.println("\nElimina vertice test:");
        	
        	Triangolo test = (Triangolo) q.eliminaVertice("test", 0);
        	System.out.println(test);
        	
        	Triangolo NonLoSo = (Triangolo) ret.eliminaVertice("NonLoSo", 3);
        	System.out.println(NonLoSo);
        	
    	// Elimina vertice
        	System.out.println("\nEsempio eccezione:");
        	
        	PoligonoConvesso exc = test.inserisciVertice("Ecc", e);
        	
	    }
	    catch(simpleExc s){
	    	System.err.println(s.getMessage());
	    }
	}

}
