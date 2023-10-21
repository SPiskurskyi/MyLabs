package ki307.piskurskyi.lab4;

import java.io.*;	

/**
* Ship Application class implements main method for Abstract Ship class possibilities demonstration
* @author Serhii Piskurskyi
* @version 1.0
*/

public class ShipApp {

	/**
	* @param args
	* @throws FileNotFoundException
	*/
	public static void main(String[] args) throws FileNotFoundException
	{
		Frigate frigate = new Frigate("Frigate Ship", 20);
        frigate.performActions();
        frigate.dispose();
	}

}
