package vertice;

import vertice.Punto;

public class Vertice extends Punto{ 
	private double info;
	
	public Vertice(Punto p, double info){
		super(p);
		this.info=info;
	}
	public Vertice(Punto p){
		this(p, 0);
	}
	public Vertice(){
		super(0,0);
		this.info=0;
	}

	protected Vertice(Vertice v){
		super(v);
		this.info = v.getInfo();
	}
	
	public double getInfo() {
		return info;
	}
	public void setInfo(double info) {
		this.info = info;
	}
	
	public static double AngoloVertici(final Vertice a, final Vertice b, final Vertice c){
		// Calcola l'angolo del vertice B, compreso tra A e C
	    Punto ab = new Punto( b.getX() - a.getX(), b.getY() - a.getY() );
	    Punto cb = new Punto( b.getX() - c.getX(), b.getY() - c.getY() );

	    double dot = (ab.getX() * cb.getX() + ab.getY() * cb.getY() );
	    double cross = (ab.getX() * cb.getY() - ab.getY() * cb.getX());

	    double alpha = Math.atan2(cross, dot);
	    return (alpha * 180 / Math.PI);
	}
	
	@Override
	public String toString() {
		return "Vertice: (" + this.getX() + "," + this.getY() + ") " + info;
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Vertice)) 
			return false;

		if(this == obj) 
			return true;

		Vertice other = (Vertice)obj;
		return super.equals(other) && other.info==info;
	}
	
	@Override
	public Vertice clone(){ 
		return new Vertice(this);
	}
	
}





