package com.sharma;

public class Main {

	public static void main(String[] args) {
		
		Shape s = new Square(5);
		Shape r = new Rectangle(4, 3);
		Rectangle rs = new Square(5);
		
		show(s);
		show(r);
		show(rs);
	}

	private static void show(Shape r) {
		System.out.println("Area" + r.area());
		System.out.println();
		System.out.println("Perimeter" + r.perimeter());
		
	}

}
