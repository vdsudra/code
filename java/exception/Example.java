class Ex{
	public static void main(String [] arg){
		int i = 50;
		try{
		System.out.println(i/0);
		System.out.println("Try..");
	}
		/*
	catch(ArithmeticException e){
		System.out.println("Exception:"+e.getMessage());
	}*/
	finally{
		System.out.println("In finally");
	}
		System.out.println("Cont..");
	}
}
