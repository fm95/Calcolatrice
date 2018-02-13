
public class Punto{
	private double x, y;
	
	public Punto(double x, double y){		
		this.x=x;;
		this.y=y;
	}
	public Punto(){
		this(0,0);
	}
	
	protected Punto(Punto p){
		this.x=p.getX();
		this.y=p.getY();
	}
	
	public double getX() {
		return x;
	}
	public void setX(double x) {
		this.x = x;
	}
	public double getY() {
		return y;
	}
	public void setY(double y) {
		this.y = y;
	}
	
	public static double distanza(final Punto p1, final Punto p2){
		double dX = ((p1.getX()-p2.getX())*(p1.getX()-p2.getX()));
	    double dY = ((p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
	    return Math.sqrt( dX + dY );
	}
	public static double determinante(final Punto p1, final Punto p2){
		return (p1.x * p2.y) - (p1.y * p2.x);
	}
	
	@Override
	public String toString() {
		return "Punto: (" + x + "," + y + ")";
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Punto)) 
			return false;
		
		if(this == obj) 
			return true;

		Punto p = (Punto)obj;
		return p.x==x && p.y==y;
	}
	
	@Override
	public Punto clone(){
		return new Punto(this);
	}

}
