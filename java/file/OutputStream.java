import java.io.*;

class example{

	public static void main(String[] arg) throws IOException{
		FileOutputStream fout;
		fout = new FileOutputStream("temp.text");
		String str="This is Java";
		char arr[]= str.toCharArray();
		int i;
		for (i=0;i<str.length();i++){
			fout.write(arr[i]);
		}
		fout.close();
	}
}
