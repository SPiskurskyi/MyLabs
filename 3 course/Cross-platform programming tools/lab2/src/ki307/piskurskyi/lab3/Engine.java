package ki307.piskurskyi.lab3;

import java.io.*;

/**
* Class <code>Engine</code> implements ship`s engine
*
* @author Serhii Piskurskyi
* @version 1.0
*/
class Engine 
{
	private String type;
    private double power;
    private boolean running;
	/**
	* Default Constructor
	*/
    public Engine() {
        this.type = "Unknown type of engine";
        this.power = 0.0;
        this.running = false;
    }
	/**
	* Constructor
	* @param <code>type</code> 
	* @param <code>power</code> 
	*/
    public Engine(String type, double power) {
        this.type = type;
        this.power = power;
        this.running = false;
    }
    /**
	* Method sets engine type
	* @param <code>type</code>
	*/
    public void setType(String type) {
        this.type = type;
    }
    /**
	* Method sets engine power
	* @param <code>power</code>
	*/
    public void setPower(double power) {
        this.power = power;
    }
    /**
	* Method gets engine type
	* @return <code>type</code>
	*/
    public String getType() {
        return type;
    }
    /**
	* Method gets engine type
	* @return <code>type</code>
	*/
    public double getPower() {
        return power;
    } 
    /**
	* Method gets engine status
	* @return <code>type</code>
	*/
    public boolean isRunning() {
        return running;
    }
    /**
	* Method implements turn on engine
	*/
    public void startEngine() {
        this.running = true;
    }
    /**
	* Method implements turn off engine
	*/
    public void stopEngine() {
        this.running = false;
    }
    /**
	* Method checks if engine has enough power
	* @return true/false
	*/
    public boolean hasEnoughPower(double requiredPower) {
        return power >= requiredPower;
    }
    /**
	* Method prints engine status
	*/
    public void printStatus() {
        if (running) {
            System.out.println("Engine enabled.");
        } else {
            System.out.println("Engine disabled.");
        }
    }
	
}