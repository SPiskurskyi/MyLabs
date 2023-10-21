package ki307.piskurskyi.lab7;

import java.util.ArrayList;
import java.util.List;
/**
* Class <code>Wagon</code> Implements FIOCalc class
* @author Serhii Piskurskyi
* @version 1.0
*/
public class Wagon<T extends Data> {
    private List<T> items;
    /**
	* Constructor
	*/
    public Wagon() {
        items = new ArrayList<>();
    }
    /**
	* Method adds item to collection
	* @param item 
	*/
    public void add(T item) {
        items.add(item);
    }
    /**
	* Method removes item from collection
	* @param item 
	*/
    public void remove(T item) {
        items.remove(item);
    }
    /**
	* Method returns size of collection 
	* @return size 
	*/
    public int getItemCount() {
        return items.size();
    }
    /**
	* Method returns item collection
	* @return collection 
	*/
    public List<T> getItems() {
        return items;
    }
    /**
	* Method return max weight item
	* @return item 
	*/
    public T findMax()
    {
	    if (!items.isEmpty())
	    {
		    T max = items.get(0);
		    for (int i=1; i< items.size(); i++)
		    {
		    	if ( items.get(i).compareTo(max) > 0 )
		    		max = items.get(i);
		    }
		    return max;
	    }
	    return null;
    }
}
/**
* Interface <code>Data</code> implements data 
* @author Sehii Piskurskyi
* @version 1.0
*/
interface Data extends Comparable<Data>
{
	public int getWeight();
}
