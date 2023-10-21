package ki307.piskurskyi.lab7;
/**
* Class <code>WagonApp</code> Implements driver for Wagon class
* @author Serhii Piskurskyi
* @version 1.0
*/
public class WagonApp {
    public static void main(String[] args) {
        Wagon<Passenger> passengerWagon = new Wagon<>();
        passengerWagon.add(new Passenger("Passenger 1",70));
        passengerWagon.add(new Passenger("Passenger 2",85));
        passengerWagon.add(new Passenger("Passenger 3",60));
        passengerWagon.add(new Passenger("Passenger 4",75));
        passengerWagon.add(new Passenger("Passenger 5",90));

        Wagon<Cargo> cargoWagon = new Wagon<>();
        cargoWagon.add(new Cargo("Cargo 1", 20000));
        cargoWagon.add(new Cargo("Cargo 2",35000));
        cargoWagon.add(new Cargo("Cargo 3",15000));
        cargoWagon.add(new Cargo("Cargo 4",20000));
        cargoWagon.add(new Cargo("Cargo 5",30000));

        System.out.println("The number of passengers in the wagon: " + passengerWagon.getItemCount());
        for (Passenger passenger : passengerWagon.getItems()) {
            System.out.println("Passenger: " + passenger.getName() + " weight - " + passenger.getWeight() + " kg");
        }
        System.out.println("\nHighest passenger weight in Wagon: " + passengerWagon.findMax().getWeight() + " kg\n");
        
        System.out.println("\nThe amount of cargo in the wagon: " + cargoWagon.getItemCount());
        for (Cargo cargo : cargoWagon.getItems()) {
            System.out.println("Cargo: " + cargo.getDescription() + " weight - " + cargo.getWeight() + " kg");
        }
        System.out.println("\nHighest cargo weight in Wagon: " + cargoWagon.findMax().getWeight()  + " kg\n");
    }
}
