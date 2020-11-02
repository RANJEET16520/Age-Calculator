package com.sharma;
import java.sql.*;
import java.util.Scanner;

public class Main1 {

	public static void main(String[] args) throws SQLException {
		
		Connection con = DriverManager.getConnection("jdbc:derby:d:/trgdg/empdb");
		
		String sql = "insert into employee values(?,?,?,?)";
		PreparedStatement pst = con.prepareStatement(sql);
		Scanner sc = new Scanner(System.in);
		
		while (true) {
			
			System.out.println("Enter empid, name, sal, dob(YYYY-MM-DD)");
			int eid = sc.nextInt();
			if (eid == 0) {
				System.out.println("BOOO wrong choice");
				break;
			}
			String name = sc.next();
			Float salary = sc.nextFloat();
			String dob = sc.next();
			
			pst.setInt(1, eid);
			pst.setString(2, name);
			pst.setFloat(3, salary);
			pst.setString(4, dob);
			
			pst.executeUpdate();
		}
		
		con.close();
	}

}
