import java.io.*;
class Throws{
	public static void main(String [] arg)throws IOException{
		System.out.println("Before Exception");
		try{
		System.out.println("In Try block");
		throw new IOException("Ok!!");
		//System.out.println("After Exception");
		}
		catch(IOException e){
		System.out.println("In Catch block:"+ e.getMessage());
		}
		System.out.println("End of main");
	}
}
