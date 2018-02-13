
import java.util.ArrayList;

public class Triangolo extends PoligonoConvesso{
	protected static final int numLati=3;
	
	public Triangolo(String name, final ArrayList<Vertice> v) throws simpleExc {
		super(name, v, 3);
	}

	protected Triangolo(Triangolo t){
		super(t);
	}
	
	@Override
	public double getSommaAngoli() {
		return 180;
	}

	@Override
	public int getNumLati() {
		return numLati;
	}

	@Override
	public double getPerimetro() 
	{
		double c1 = Punto.distanza(Vertici.get(0), Vertici.get(1));
	    double c2 = Punto.distanza(Vertici.get(1), Vertici.get(2));
	    double c3 = Punto.distanza(Vertici.get(2), Vertici.get(0));
	    return c1 + c2 + c3;
	}

	@Override
	public double getArea() 
	{ // triangolo generico
	    double x0 = Vertici.get(0).getX(), y0=Vertici.get(0).getY();
	    double x1 = Vertici.get(1).getX(), y1=Vertici.get(1).getY();
	    double x2 = Vertici.get(2).getX(), y2=Vertici.get(2).getY();
	    
	    return Math.abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2;
	}
	
	public double getApotema() throws simpleExc
	{ // raggio della circonferenza inscritta nel triangolo
	    if(isRegolare())
	        return 0.289*getLato(Vertici.get(0).getInfo(), -1);
	    else
	        throw new simpleExc("Non si puo' calcolare l'apotema di un triangolo irregolare!");
	}
	
    public boolean isIsoscele()
    { // 2 lati uguali
        double c1 = Punto.distanza(Vertici.get(0), Vertici.get(1));
        double c2 = Punto.distanza(Vertici.get(1), Vertici.get(2));
        double c3 = Punto.distanza(Vertici.get(2), Vertici.get(0));
        return (c1==c2 || c1==c3 || c2==c3);
    }
    
    public boolean isScaleno()
    { // tutti lati & angoli diversi
        return !isIsoscele() && !isEquilatero();
    }
    
    public boolean isRettangolo()
    { // un angolo di 90 gradi
        return (calcolaAngolo(Vertici,0)==90
                || calcolaAngolo(Vertici,1)==90
                || calcolaAngolo(Vertici,2)==90);
    }
    
    public boolean isOttusangolo()
    { // un angolo > 90 gradi
        return (calcolaAngolo(Vertici,0)>90
        	       || calcolaAngolo(Vertici,1)>90
        	       || calcolaAngolo(Vertici,2)>90);
    }
    
    public boolean isAcutangolo()
    { // tutti gli angoli < 90 gradi
        return (calcolaAngolo(Vertici,0)<90
           && calcolaAngolo(Vertici,1)<90
           && calcolaAngolo(Vertici,2)<90);
    }

    @Override
	public String toString() {
		return super.toString();
	}
    
    @Override
	public boolean equals(Object obj) {
    	if(!(obj instanceof Triangolo)) 
			return false;
		if(this == obj) 
			return true;
		return this.getArea()==((Triangolo)obj).getArea();
	}
    
    @Override
	public Figura clone() {
		return new Triangolo(this);
	}

}
