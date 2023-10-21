package ki307.piskurskyi.lab4;

import java.io.*;
/**
*  Class <code>Frigate</code> implements frigate
* @author Sehii Piskurskyi
* @version 1.0
*/
public class Frigate extends Ship implements ICombatShip {
    private int numberOfCannons;
    /**
	* Constructor
	* @throws FileNotFoundException
	* @param <code>name</code>
	* @param <code>numberOfCannons</code>
	*/
    public Frigate(String name, int numberOfCannons) throws FileNotFoundException {
        super(name);
        this.numberOfCannons = numberOfCannons;
    }
    /**
   	* Method implements firing from cannons
   	*/
    @Override
    public void fireCannons() {
    	System.out.println(getName() + " fires " + numberOfCannons + " cannons!");
    	fout.print(getName() + " fires " + numberOfCannons + " cannons!\n");
    }
    /**
   	* Method implements engaging enemy
   	*/
    @Override
    public void engageEnemy() {
    	System.out.println(getName() + " engages the enemy!");
    	fout.print(getName() + " engages the enemy!\n");
    }
    /**
   	* Method that performs actions
   	*/
    @Override
    public void performActions() {
        fireCannons();
        engageEnemy();
    }
}
