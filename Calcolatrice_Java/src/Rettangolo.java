
import java.util.ArrayList;

public class Rettangolo extends Quadrilatero { 
	public Rettangolo(String name, final ArrayList<Vertice> v) throws simpleExc {
		super(name, v);
	}
	
	protected Rettangolo(Rettangolo r) {
		super(r);
	}
	
	@Override
	public double getPerimetro()
	{
		double a = Punto.distanza(Vertici.get(0), Vertici.get(1));
	    double b = Punto.distanza(Vertici.get(1), Vertici.get(2));
	    return (a+b)*2;
	}
	@Override
	public double getArea()
	{
		double a = Punto.distanza(Vertici.get(0), Vertici.get(1));
	    double b = Punto.distanza(Vertici.get(1), Vertici.get(2));
	    return a*b;
	}
	
	@Override
	public String toString() {
		return super.toString();
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Rettangolo)) 
			return false;
		if(this == obj) 
			return true;
		else
			return this.getArea()==((Rettangolo)obj).getArea();
	}
	
	@Override
	public Rettangolo clone(){
		return new Rettangolo(this);
	}
	
}
