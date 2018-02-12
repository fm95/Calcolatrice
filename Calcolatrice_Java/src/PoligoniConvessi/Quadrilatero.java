package PoligoniConvessi;

import java.util.ArrayList;

import Eccezioni.simpleExc;

import vertice.*;

public class Quadrilatero extends PoligonoConvesso {
	protected static final int numLati=4;
	
	public Quadrilatero(String name, final ArrayList<Vertice> v) throws simpleExc {
		super(name, v, 4);
	}

	protected Quadrilatero(Quadrilatero q) {
		super(q);
	}
	
	@Override
	public double getSommaAngoli() 
	{ return 360; }

	@Override
	public int getNumLati() 
	{ return numLati; }

	@Override
	public double getPerimetro() {
		double per=0;
	    for(int i=0; i<Vertici.size(); ++i)
	    {
	        if(i+1 == Vertici.size())
	            per += Punto.distanza(Vertici.get(i), Vertici.get(0));
	        else
	            per += Punto.distanza(Vertici.get(i), Vertici.get(i+1));
	    }
	    return per;
	}

	@Override
	public double getArea() {
	// formula di Brahmagupta
	    double p = getPerimetro()/2;
	    double a = Punto.distanza(Vertici.get(0), Vertici.get(1));
	    double b = Punto.distanza(Vertici.get(1), Vertici.get(2));
	    double c = Punto.distanza(Vertici.get(2), Vertici.get(3));
	    double d = Punto.distanza(Vertici.get(3), Vertici.get(0));
	    return Math.sqrt((p-a)*(p-b)*(p-c)*(p-d));
	}

	public double getDiagolale(int v1, int v2) throws simpleExc
	{
		if(v1>=0 && v1<Vertici.size() && v2>=0 && v2<Vertici.size()
	            && (v1==v2+2 || v2==v1+2))
	    {
	        if((v1==Vertici.size()-1 && v2==0)
	                || (v1==0 && v2==Vertici.size()-1))
	            return Punto.distanza(Vertici.get(0), Vertici.get(Vertici.size()-1));
	        else
	            return Punto.distanza(Vertici.get(v1), Vertici.get(v2));
	    }
	    else
	        throw new simpleExc("Posizioni non valide!");
	}

	@Override
	public String toString() {
		return super.toString();
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Quadrilatero)) 
			return false;
		if(this == obj) 
			return true;
		Quadrilatero p = (Quadrilatero)obj;
		return this.equals(p); 
	}

	@Override
	public Quadrilatero clone() {
		return new Quadrilatero(this);
	}
	
}
