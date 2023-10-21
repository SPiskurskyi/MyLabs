package ki307.piskurskyi.lab3;

import java.io.*;
/**
* Class <code>Ship</code> implements ship
40
* @author Sehii Piskurskyi
* @version 1.0
*/

public class Ship {
	private ShipProperty property;
    private Engine engine;
    private ControlSystem controlSystem;
	private PrintWriter fout;
	/**
	* Constructor
	* @throws FileNotFoundException
	*/
	public Ship() throws FileNotFoundException
	{
		this.property = new ShipProperty();
        this.engine = new Engine();
        this.controlSystem = new ControlSystem();
		fout = new PrintWriter(new File("Log.txt"));
		fout.print("Ship created\n");
	}
	/**
	* Method implements turning on engine
	*/
	public void startEngine() {
        engine.startEngine();
        fout.print("Engine started\n");
    }
	/**
	* Method implements turning off engine
	*/
    public void stopEngine() {
        engine.stopEngine();
        fout.print("Engine stoped\n");
    }

    /**
	* Method returns property info
	* @return <code>property</code>
	*/
    public String getPropertyInfo() {
        return property.getInfo();
    }

    /**
	* Method implements turning on autopilot
	*/
    public void enableAutopilot() {
        controlSystem.enableAutopilot();
        fout.print("Autopilot enabled\n");
    }

    /**
	* Method implements turning off autopilot
	*/
    public void disableAutopilot() {
        fout.print("Autopilot disabled\n");
    }

    /**
	* Method implements printing status of control system
	*/
    public void printControlSystemStatus() {
        controlSystem.printStatus();
    }

    /**
	* Method implements increase ship`s speed
	* @param <code>amount</code> the amount be which the speed will increase
	*/
    public void increaseSpeed(int amount) {
        controlSystem.increaseSpeed(amount);
        fout.print("Speed was increased to " + amount + " \n");
    }
    /**
	* Method implements decrease ship`s speed
	* @param <code>amount</code> the amount be which the speed will decrease
	*/
    public void decreaseSpeed(int amount) {
        controlSystem.decreaseSpeed(amount);
        fout.print("Speed was decreased to " + amount + " \n");
    }

    /**
   	* Method checks if ship can start moving 
   	*/
    public boolean canMove() {
        return engine.isRunning() && controlSystem.isAutopilotEnabled() && controlSystem.getCurrentSpeed() > 0;
    }
    /**
   	* Method prints info about ship
   	*/
    public void printShipInfo() {
        System.out.println("Info about ship:");
        System.out.println(getPropertyInfo());
        System.out.println("Engine status:");
        engine.printStatus();
        System.out.println("Control system status:");
        printControlSystemStatus();
    }

    /**
	* Method returns property object
	* @return <code>property</code>
	*/
    public ShipProperty getProperty() {
        return property;
    }
    /**
   	* Method sets property object
   	* @param <code>property</code>
   	*/
    public void setProperty(ShipProperty property) {
        this.property = property;
    }

    /**
   	* Method returns engine object
   	* @return <code>engine</code>
   	*/
    public Engine getEngine() {
        return engine;
    }
    /**
   	* Method sets engine object
   	* @param <code>engine</code>
   	*/
    public void setEngine(Engine engine) {
        this.engine = engine;
    }
    /**
   	* Method gets control system object
   	* @return <code>controlSystem</code>
   	*/
    public ControlSystem getControlSystem() {
        return controlSystem;
    }
    /**
   	* Method sets control system object
   	* @param <code>controlSystem</code>
   	*/
    public void setControlSystem(ControlSystem controlSystem) {
        this.controlSystem = controlSystem;
    }
	/**
	* Method releases used recourses
	*/
	public void dispose()
	{
		fout.close();
	}
}

