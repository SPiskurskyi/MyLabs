# lab9.py
from package1.Ship import Ship
from package1.Frigate import Frigate

# Define the main function
def main():
    # Create Ship and Frigate objects
    my_ship = Ship("Nostromo", 190, 29)
    my_frigate = Frigate("Defender", 150, 25, "high")

    # Call methods to print information about these objects
    print("Information about my ship:")
    my_ship.print_info()

    print("\nInformation about my frigate:")
    my_frigate.print_info()

# Run the main function when this script is executed
if __name__ == "__main__":
    main()
