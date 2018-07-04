interface I1{
	void f1();
}
interface I2{
	void f2();
}

interface I3 extends I1,I2{
	void f3();
} 

class A implements I3{

	public void f1(){
		System.out.println("I1 f called");
	}
	public void f2(){
		System.out.println("I2 f called");
	}
	public void f3(){
		System.out.println("I3 f called");
	}
}

class Example{
	public static void main(String[] arg){
		A a = new A();
		a.f1();
		a.f2();
		a.f3();
		I2 p = new A();
		p.f1();
		p.f2();
	}
}
