package PoligoniConvessi;

import java.util.ArrayList;

import Figura.*;
import vertice.*;
import Eccezioni.*;

public abstract class PoligonoConvesso extends Figura{
	private static final int limiteVertici = 20;
	protected ArrayList<Vertice> Vertici;
	
	public PoligonoConvesso(String name, final ArrayList<Vertice> v, final int nLati) throws simpleExc {
		super(name);
		if(!v.isEmpty() && nLati>2 && v.size()==nLati && nLati<=limiteVertici)
		{
			boolean test=true;
			double sum=0;
			for(int i=0; test && i<v.size(); ++i)
			{
				if(test) // tutti i vertici sono diversi
				{
					double aux = calcolaAngolo(v,i);
					if(aux<=0 || aux>=180) // calcolo gli angoli
						test=false;
					else
						sum += aux;
				}
			}
			if(test && 
					sum>=(180*(nLati-2)-0.000001) 
					&& sum<=(180*(nLati-2)+0.000001))
				Vertici = v;
			else
				throw new simpleExc("I vertici non formano un poligono convesso!");
		}
		else
			throw new simpleExc("Inserisci un numero valido di vertici!");
	}
	
	protected PoligonoConvesso(PoligonoConvesso p) // copia profonda protetta
	{
		this.Vertici = new ArrayList<Vertice>(p.Vertici);
	}
	
	private static PoligonoConvesso costruisci(String s, final ArrayList<Vertice> v) throws simpleExc
	{ // vector v gia' controllato!
	    if(v.size()==3)
	        return new Triangolo(s,v);
	    else if(v.size()==4)
	    {
	        Quadrilatero q = new Quadrilatero(s, v);
	        if(!q.isEquiangolo())
	           return q;
	        else if(!q.isEquilatero() && q.isEquiangolo())
	        	return new Rettangolo(s, v);
	        else if(q.isEquilatero() && q.isEquiangolo())
	        	return new Quadrato(s, v);
	    }
        return null;
	}
	
	protected static double calcolaAngolo(final ArrayList<Vertice> v, final int pos){
		if(pos==0)
	        return Vertice.AngoloVertici(v.get(v.size()-1), v.get(0), v.get(1));
	    else if((pos+1) != v.size())
	        return Vertice.AngoloVertici(v.get(pos-1), v.get(pos), v.get(pos+1));
	    else if((pos+1) == v.size())
	        return Vertice.AngoloVertici(v.get(pos-1), v.get(pos), v.get(0));
	    else
	        return -1;
	}
	
    public final PoligonoConvesso inserisciVertice(String nome, Vertice v) throws simpleExc {
        if(Vertici.size()<4)
        {
            if( WindingNumberInclusion(v, Vertici) == 0 )
            {
            	ArrayList<Vertice> aux = (ArrayList<Vertice>) Vertici.clone(); // shallow copy
            	aux.add(v);
                 return costruisci(nome, aux);
            }
            else
            	throw new simpleExc("Il nuovo poligono non e' convesso!");
        }
        return null;
    }
	public final PoligonoConvesso eliminaVertice(String nome, int pos) throws simpleExc
    { // si puo' eliminare solo da un poligono con almeno 4 vertici
        if(Vertici.size()>3)
        {
            if(pos < Vertici.size())
            {
            	ArrayList<Vertice> aux = (ArrayList<Vertice>) Vertici.clone(); // shallow copy
            	boolean b=false;
                for(int i=0; !b && i<Vertici.size(); ++i, --pos)
                {
                    if(pos==0)
                    {
                        aux.remove(i);
                        b=true;
                    }
                }
                return costruisci(nome, aux);
            }
            else
            	throw new simpleExc("Posizione non valida!");
        }
        else
            return null;
    }

	public final void modificaInfo(int pos, double info) throws simpleExc
	{ // pos & nuovoInfo
		if(pos>=0 && pos<Vertici.size())
			Vertici.get(pos).setInfo(info);
		else
			throw new simpleExc("Posizione non valida!");
	}
	public final boolean infoUguali()
    {
    	for(int i=1; i<Vertici.size(); ++i)
    	{
    		if(Vertici.get(i-1).getInfo() != Vertici.get(i).getInfo())
    			return false;
    	}
        return true;
    }
	public final double Max() 
    { 
    	double m = Vertici.get(0).getInfo();
    	for(Vertice v : Vertici)
    	{
    		if(v.getInfo() > m)
    			m=v.getInfo();
    	}
        return m;
    }
    public final double Min()
    {
    	double m = Vertici.get(0).getInfo();
    	for(Vertice v : Vertici)
    	{
    		if(v.getInfo() < m)
    			m=v.getInfo();
    	}
        return m;
    }
    public final double AVG(){
    	double m=0;
    	for(Vertice v : Vertici)
        	m += v.getInfo();
        return m/Vertici.size();
    }
    public final double Somma()
    {
    	double m=0;
    	for(Vertice v : Vertici)
        	m += v.getInfo();
        return m;
    }
    public final double Sottrazione()
    {	
    	double m=0;
    	for(Vertice v : Vertici)
        	m -= v.getInfo();
        return m;
    }
	
    public abstract double getSommaAngoli();
	public abstract int getNumLati();
	public abstract boolean equals(Object obj);
//    public abstract double getPerimetro(); ereditati da figura
//	  public abstract double getArea(); ereditati da figura
    
	public double getLato(double i1, int pos) throws simpleExc
	{ // info & pos (se sono tutte uguali)
		if(pos>=0 && pos<Vertici.size())
	    {
	        if(pos==(Vertici.size()-1) && Vertici.get(pos).getInfo()==i1)
	            return Punto.distanza(Vertici.get(pos), Vertici.get(0));
	        else if(Vertici.get(pos).getInfo()==i1)
	            return Punto.distanza(Vertici.get(pos), Vertici.get(pos+1));
	    }
	    else
	    { // info diversi, prendo i primi due che soddisfano l'uguaglianza
	        for(int i=0; i<Vertici.size(); ++i)
	        {
	            if(i==(Vertici.size()-1) && // ultimo vertice
	                    Vertici.get(i).getInfo()==i1)
	                return Punto.distanza(Vertici.get(i), Vertici.get(0));

	            else if(Vertici.get(i).getInfo()==i1) // vertice qualsiasi
	                return Punto.distanza(Vertici.get(i), Vertici.get(i+1));
	        }
	    }
	    throw new simpleExc("Info o posizione non valida!");
	}
	public double getAngolo(double i1, int pos) throws simpleExc
	{ // info & pos (se sono tutte uguali)
		if(pos>=0 && pos<Vertici.size() && Vertici.get(pos).getInfo()==i1)
			return calcolaAngolo(Vertici,pos);
		else
		{
			for(int i=0; i<Vertici.size(); ++i)
			{
				if(Vertici.get(i).getInfo()==i1)
					return calcolaAngolo(Vertici,i);
			}
		}
		throw new simpleExc("Info o posizione non valida!");	
	}
    
	public final int getNumDiagonali(){ 
		return getNumLati() * (getNumLati()-3)/2 ; 
	}
    public final boolean isEquiangolo()
    {
    	for(int i=0; i<Vertici.size(); ++i)
    	{
			if(calcolaAngolo(Vertici,0) != calcolaAngolo(Vertici,i))
				return false;
    	}
    	return true;
    }
    public final boolean isEquilatero()
    { 
		double dist = Punto.distanza(Vertici.get(0), Vertici.get(1));
		for(int i=2; i<Vertici.size(); ++i)
		{
			if(dist != Punto.distanza(Vertici.get(i-1), Vertici.get(i)))
				return false;
		}
		return isEquiangolo();
    }
    public final boolean isRegolare(){ 
    	return isEquilatero() && isEquiangolo(); 
	}
   
    static int WindingNumberInclusion(final Vertice P, final ArrayList<Vertice> V)
    {// Winding Number Algorithm
        int wn = 0;
        for(int i=1; i<V.size(); i++)
        {
            if (V.get(i-1).getY() <= P.getY())
            {
                if (V.get(i).getY()  > P.getY())
                {
                    double l = isLeft(V.get(i-1), V.get(i), P);
                    if (l > 0)
                        ++wn;
                    else if (l == 0)
                        return 0;
                }
            }
           else
            {
                if (V.get(i).getY() <= P.getY()) 
                {
                    double l = isLeft(V.get(i-1), V.get(i), P);
                    if (l < 0)
                        --wn;
                    else if (l == 0)
                        return 0;
                }
            }
        }
        return wn;
    }
	static double isLeft(final Vertice v0, final Vertice v1, final Vertice v2)
	{
		return ( (v1.getX() - v0.getX()) * (v2.getY() - v0.getY())
	             - (v2.getX() -  v0.getX()) * (v1.getY() - v0.getY()) );
	}
    
    @Override
	public String toString() 
    {
    	String result = name + ": ";
    	for(int i=0; i<Vertici.size(); ++i){
    		result += "("+Vertici.get(i).getX()+","+Vertici.get(i).getY()+") ";
    		result += Vertici.get(i).getInfo() + " ";
    		result += "[" + calcolaAngolo(Vertici, i) + "°]";
   
    		if(i!=(Vertici.size()-1))
    			result += " > ";
    	}
    	return result;
	}
	
}
