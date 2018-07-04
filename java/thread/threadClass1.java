class A extends Thread{
	int j,k;
	A(int j , int k){
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
class B extends Thread{
	int j,k;
	B(int j , int k){
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
		A t1 = new A(3,7);
		B t2 = new B(9,14);
		t1.start();
		t2.start();
	}
}

