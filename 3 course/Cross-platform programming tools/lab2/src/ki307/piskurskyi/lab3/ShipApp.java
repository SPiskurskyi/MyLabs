package ki307.piskurskyi.lab3;

import static java.lang.System.out;
import java.io.*;	

/**
* Ship Application class implements main method for Ship class possibilities demonstration
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
		Ship ship = new Ship();

        ShipProperty shipProperty = new ShipProperty("WaterShip", 5000, 150.5);
        ship.setProperty(shipProperty);

        Engine engine = new Engine("Dizel", 5000.0);
        ship.setEngine(engine);

        ControlSystem controlSystem = new ControlSystem("Auto");
        ship.setControlSystem(controlSystem);

        ship.printShipInfo();

        ship.startEngine();
        ship.enableAutopilot();

        ship.increaseSpeed(10);

        if (ship.canMove()) {
            System.out.println("Ship moving.");
        } else {
            System.out.println("Ship not moving.");
        }

        ship.printShipInfo();
        ship.dispose();
	}

}
