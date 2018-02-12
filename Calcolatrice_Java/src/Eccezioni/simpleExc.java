package Eccezioni;

public class simpleExc extends Exception {

	private String errore;
	
	public simpleExc(String errore){
		this.errore=errore;
	}
	public simpleExc(){
		this("Eccezione controllata!");
	}

	@Override
	public String getMessage(){
		return errore;
	}
	
}
