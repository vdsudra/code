class Box{
	public int x,y;

	public void setData(int a, int b){
		x=a;
		y=b;
	}

	public void showData(){
		System.out.println("X:"+x);
		System.out.println("Y:"+y);
	}

}


class Exm2{
public static void main(String args[]){

	Box b = new Box();
	b.setData(10,20);
	b.showData();
}

}
