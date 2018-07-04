class A implements Runnable{
	public void run(){
		int i;
		for(i=0;i<5;i++){
			System.out.println("Class A() I: "+i);
		}
	}
}
class B implements Runnable{
	public void run(){
		int i;
		for(i=0;i<5;i++){
			System.out.println("Class B() I: "+i);
		}
	}
}

class T1{
	public static void main(String[] arg){
		Thread t1 = new Thread(new A());
		Thread t2 = new Thread(new B());
		t1.start();
		t2.start();
	}
}

