package ki307.piskurskyi.lab7;

/**
* Class <code>Cargo</code> Implements passenger 
* @author Serhii Piskurskyi
* @version 1.0
*/
public class Cargo implements Data {
    private String description;
    private int weight;
    /**
	* Constructor
	* @param description
	* @param weight
	*/
    public Cargo(String description, int weight) {
        this.description = description;
        this.weight = weight;
    }
    /**
   	* Method return item`s description
   	* @return description 
   	*/
    public String getDescription() {
        return description;
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