
import java.util.ArrayList;

public final class Quadrato extends Rettangolo {
	public Quadrato(String name, final ArrayList<Vertice> v) throws simpleExc {
		super(name, v);
	}
	
	protected Quadrato(Quadrato q) {
		super(q);
	}
	
	@Override
	public double getPerimetro()
	{
		double a = Punto.distanza(Vertici.get(0), Vertici.get(1));
	    return a*4;
	}
	@Override
	public double getArea()
	{
		double a = Punto.distanza(Vertici.get(0), Vertici.get(1));
	    return a*a;
	}
	
	public double getApotema() throws simpleExc { 
		return 0.5 * getLato(Vertici.get(0).getInfo(), 0); 
	}
	
	@Override
	public String toString() {
		return super.toString();
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Quadrato)) 
			return false;
		if(this == obj) 
			return true;
		else
			return this.getArea()==((Quadrato)obj).getArea();
	}
	
	@Override
	public Quadrato clone(){
		return new Quadrato(this);
	}
	
}
