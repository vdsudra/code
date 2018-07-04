class A implements Runnable{
	int j,k;
	A(int j, int k){
		this.j=j;
		this.k=k;
	}

	public void run(){
		int i;
		for(i=j;i<k;i++){
			System.out.println("Class A() I: "+i);
		}
	}
}
class B implements Runnable{
	int j,k;
	B(int j, int k){
		this.j=j;
		this.k=k;
	}
	public void run(){
		int i;
		for(i=j;i<k;i++){
			System.out.println("Class B() I: "+i);
		}
	}
}

class T1{
	public static void main(String[] arg){

		A a = new A(2,7);
		B b =new B(11,17);
		Thread t1 = new Thread(a);
		Thread t2 = new Thread(b);
		t1.start();
		t2.start();
	}
}

