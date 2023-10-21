# Frigate.py
from package1.Ship import Ship

# Define the Frigate class, inheriting from Ship
class Frigate(Ship):
    # Initialize the frigate with name, length, max_speed, and firepower attributes
    def __init__(self, name, length, max_speed, firepower):
        super().__init__(name, length, max_speed)
        self.firepower = firepower

    # Method to simulate the frigate firing its cannons
    def fire_cannons(self):
        print(f"The {self.name} is firing its cannons with {self.firepower} firepower!")

    def print_info(self):
        super().print_info()
        print(f"Firepower: {self.firepower}")
       
# Test the Frigate class
if __name__ == "__main__":
    my_frigate = Frigate("Defender", 150, 25, "high")
    my_frigate.print_info()
    my_frigate.sail()
    my_frigate.anchor()
    my_frigate.fire_cannons()

