package ki307.piskurskyi.lab4;


/**
* Class <code>ShipProperty</code> implements ship properties
coordinate system
*
* @author Serhii Piskurskyi
* @version 1.0
*/
class ShipProperty
{
	private String name;
    private int capacity;
    private double length;
	/**
	* Default Constructor
	*/
    public ShipProperty() {
        this.name = "Unknown name of ship";
        this.capacity = 0;
        this.length = 0.0;
    }
    /**
	* Constructor
	* @param <code>name</code> 
	* @param <code>capacity</code> 
	* @param <code>length</code> 
	*/
    public ShipProperty(String name, int capacity, double length) {
        this.name = name;
        this.capacity = capacity;
        this.length = length;
    }
	/**
	* Method sets ship`s name
	* @param <code>name </code>
	*/
    public void setName(String name) {
        this.name = name;
    }
	/**
	* Method sets ship`s capacity
	* @param <code>capacity</code>
	*/
    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }
	/**
	* Method sets ship`s length 
	* @param <code>length</code>
	*/
    public void setLength(double length) {
        this.length = length;
    }
	/**
	* Method gets ship`s name
	* @return <code>name</code>
	*/
    public String getName() {
        return name;
    }
    /**
	* Method gets ship`s capacity
	* @return <code>capacity</code>
	*/
    public int getCapacity() {
        return capacity;
    }
    /**
	* Method gets ship`s length
	* @return <code>length</code>
	*/
    public double getLength() {
        return length;
    }
    /**
	* Method gets ship`s ship`s properties info
	* @return <code>info</code>
	*/
    public String getInfo() {
        return "Name of ship: " + name + "\n" +
               "Capacity: " + capacity + " tons\n" +
               "Ship length: " + length + " meters";
    }
    /**
	* Method checks if ship is large
	* @return true/false
	*/
    public boolean isLargeShip() {
        return length > 100.0;
    }

}