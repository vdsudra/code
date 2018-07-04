import java.io.*;
class Throws{
	public static void main(String [] arg)throws IOException{
		System.out.println("Before Exception");
		throw new IOException();
//		System.out.println("After Exception");
	}
}
