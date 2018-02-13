
public abstract class Figura{  
	private static final int maxLengthNome = 14;
	protected String name;
	
	public Figura(String name){
		setNome(name);
	}
	public Figura(){
		this("");
	}
	
	protected Figura(Figura f){
		this.name = f.getNome();
	}
	
	public String getNome(){
		return name;
	}
	public void setNome(String name){
		if(name.length()>14)
			throw new IllegalArgumentException("Nome troppo lungo!");
		this.name=name;
	}
	
	public abstract double getPerimetro();
	public abstract double getArea();
	
	public abstract Figura clone();
	
	@Override
	public String toString(){
		return name;
	}

	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Figura)) 
			return false;

		if(this == obj) 
			return true;

		Figura f = (Figura)obj;
		return f.name == name;
	}
	
}