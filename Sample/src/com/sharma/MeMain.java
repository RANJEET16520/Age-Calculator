package com.sharma;

import java.util.ArrayList;
import java.util.Scanner;

public class MeMain {

	public static void main(String[] args) {
		
		String lst[] = new String[10];
		
		Scanner sc = new Scanner(System.in);
		System.out.println("heloo");
		int i =0;
		while(i<10) {
			lst[i] = sc.next();
			i+=1;
		}
		for(String s : lst) {
			System.out.println(s);
			
		}
		String s[] = lst;
		s[1] = "100";
		for(String s1 : lst) {
			System.out.println(s1);
			
		}
		
		
		

	}

}
