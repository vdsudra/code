import java.io.*;

class example{

	public static void main(String[] arg) throws IOException{
	
		File f = new File("/home/vinay/tran/java/file/temp.txt");
		f.createNewFile();
		System.out.println("Is Exist: "+f.exists());
		System.out.println("Size: "+f.length());
		f.delete();
	}
}
