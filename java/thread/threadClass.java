class A extends Thread{
	public void run(){
		int i;
		for(i=0;i<5;i++){
			System.out.println("Class A() I: "+i);
		}
	}
}
class B extends Thread{
	public void run(){
		int i;
		for(i=0;i<5;i++){
			System.out.println("Class B() I: "+i);
		}
	}
}

class T1{
	public static void main(String[] arg){
		A t1 = new A();
		B t2 = new B();
		t1.start();
		t2.start();
	}
}

