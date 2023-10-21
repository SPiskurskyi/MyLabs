package ki307.piskurskyi.lab6;

import java.io.*;
import java.util.*;
/**
* Class <code>FIOApp</code> Implements driver for FIOCalc class
* @author Serhii Piskurskyi
* @version 1.0
*/
public class FIOApp {
	/**
	* @param args
	*/
	public static void main(String[] args) throws FileNotFoundException, IOException
	{
		// TODO Auto-generated method stub
		FIOCalc obj = new FIOCalc();
		Scanner s = new Scanner(System.in);
		System.out.print("Enter data: ");
		double data = s.nextDouble();
		obj.calculate(data);
		System.out.println("Result before write is: " + obj.getResult());
		obj.writeResTxt("textRes.txt");
		obj.writeResBin("BinRes.bin");
		obj.readResBin("BinRes.bin");
		System.out.println("Result from binary format is: " + obj.getResult());
		obj.readResTxt("textRes.txt");
		System.out.println("Result from text format is: " + obj.getResult());
	}
}