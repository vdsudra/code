interface I1{
	int x=100;
	void f1();
}
interface I2{
	void f2();
}

class A implements I1, I2{

	public void f1(){
		x++;
		System.out.println("I1 f called" + x);
	}
	public void f2(){
		System.out.println("I2 f called");
	}
}

class Example1{
	public static void main(String[] arg){
		A a = new A();
		a.f1();
		a.f2();
	}
}
