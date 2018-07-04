import java.io.*;

class example{

	public static void main(String[] arg) throws IOException{
		FileInputStream fin;
		int i;
		fin = new FileInputStream("temp.text");
		do{
		i=fin.read();
		System.out.println((char)i);
		}while(i != -1);
		fin.close();
	}
}
