import java.util.Scanner;
class Account{
	private int bal;
	Account(int b){
		bal = b;
	}

	public boolean isBalance(int m){
		if(bal < m)
			return false;
		else 
			return true;
	}

	public void withDraw(int m){
		bal = bal - m;
		System.out.println("Amount Deducted :"+bal);
	}
}
class A extends Thread{
	public void run(){
		int i;
		for(i=0;i<5;i++){
			System.out.println("Class A() I: "+i);
		}
	}
}

class Customer implements Runnable{
	private Account ac;
	Customer(Account a){
		ac=a;
	}

	public void run(){
	Scanner kb = new Scanner((System.in));
	int amt = kb.nextInt();
	synchronized(ac){
	if(ac.isBalance(amt)){
		ac.withDraw(amt);
	}
	else
		System.out.println("Insufficient Balance");
	}
	}
}

class T1{
	public static void main(String[] arg){
		Account a1 = new Account(1000);
		Customer c1 = new Customer(a1);
		Customer c2 = new Customer(a1);
		Thread t1 = new Thread(c1);
		Thread t2 = new Thread(c2);
		t1.run();
		t2.run();
	}
}

