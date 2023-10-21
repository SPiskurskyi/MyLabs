package ki307.piskurskyi.lab7;

/**
* Class <code>Passenger</code> Implements passenger 
* @author Serhii Piskurskyi
* @version 1.0
*/
public class Passenger implements Data {
    private String name;
    private int weight;
    /**
	* Constructor
	* @param name
	* @param weight
	*/
    public Passenger(String name, int weight) {
        this.name = name;
        this.weight = weight;
    }
    /**
   	* Method return item`s name
   	* @return name 
   	*/
    public String getName() {
        return name;
    }
    /**
   	* Method return item`s weight
   	* @return weight 
   	*/
    public int getWeight() {
        return weight;
    }
    /**
   	* Method return highest weight of 2 items
   	* @return integer
   	*/
    public int compareTo(Data p)
    {
	    Integer s = weight;
	    return s.compareTo(p.getWeight());
    }
    
}
