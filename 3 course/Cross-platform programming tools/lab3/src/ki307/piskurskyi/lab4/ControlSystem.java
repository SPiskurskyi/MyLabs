package ki307.piskurskyi.lab4;



/**
* @author Serhii Piskurskyi
* Class <code>ControlSystem</code> implements control system
*/
class ControlSystem 
{
	private String systemType;
    private boolean autopilotEnabled;
    private int currentSpeed;
	/**
	* Default Constructor
	*/
    public ControlSystem() {
        this.systemType = "Unknown system control";
        this.autopilotEnabled = false;
        this.currentSpeed = 0;
    }
	/**
	* Constructor
	* @param <code>systemType</code> 
	*/
    public ControlSystem(String systemType) {
        this.systemType = systemType;
        this.autopilotEnabled = false;
        this.currentSpeed = 0;
    }
    /**
   	* Method gets control system type
   	* @return <code>type</code>
   	*/
    public String getSystemType() {
        return systemType;
    }
    /**
   	* Method sets control system type
   	* @param <code>type</code>
   	*/
    public void setSystemType(String systemType) {
        this.systemType = systemType;
    }
    /**
   	* Method check if autopilot is enabled
   	* @return true/false
   	*/
    public boolean isAutopilotEnabled() {
        return autopilotEnabled;
    }
    /**
	* Method implements enable autopilot
	*/
    public void enableAutopilot() {
        this.autopilotEnabled = true;
    }
    /**
	* Method implements disable autopilot
	*/
    public void disableAutopilot() {
        this.autopilotEnabled = false;
    }
    /**
   	* Method gets control system speed
   	* @return <code>speed</code>
   	*/
    public int getCurrentSpeed() {
        return currentSpeed;
    }
    /**
   	* Method sets control system speed
   	* @param <code>speed</code>
   	*/
    public void setCurrentSpeed(int currentSpeed) {
        this.currentSpeed = currentSpeed;
    }
    /**
   	* Method increases current speed
   	* @param <code>speed</code>
   	*/
    public void increaseSpeed(int amount) {
        currentSpeed += amount;
    }
    /**
   	* Method decreases current speed
   	* @param <code>speed</code>
   	*/
    public void decreaseSpeed(int amount) {
        if (currentSpeed - amount >= 0) {
            currentSpeed -= amount;
        } else {
            System.out.println("Speed cannot be less than zero.");
        }
    }
    /**
	* Method prints control system status
	*/
    public void printStatus() {
        System.out.println("Control System Type: " + systemType);
        System.out.println("Auto pilot: " + (autopilotEnabled ? "enabled" : "disabled"));
        System.out.println("Current speed: " + currentSpeed + " knots");
    }
    
    
}
