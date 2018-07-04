class Exmp2{
	public static void main(String [] arg){
		int i = 50;
		try{
			if(i < 100)
				throw new ArithmeticException("No balance");
			System.out.println("After Exception Throw");
		}
		catch(ArithmeticException e){
			System.out.println("Exception:"+e.getMessage());
		}
		finally{
			System.out.println("In finally");
		}
		System.out.println("Cont..");
	}
}
