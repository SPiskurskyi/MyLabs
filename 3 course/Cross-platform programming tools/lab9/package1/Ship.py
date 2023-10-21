# Ship.py

# Define the Ship class
class Ship:
    # Initialize the ship with name, length, and max_speed attributes
    def __init__(self, name, length, max_speed):
        self.name = name
        self.length = length
        self.max_speed = max_speed

    # Method to simulate the ship sailing
    def sail(self):
        print(f"The {self.name} is sailing at {self.max_speed} knots.")

    # Method to simulate the ship anchoring
    def anchor(self):
        print(f"The {self.name} is anchored.")

    # Method to simulate the ship sounding its horn
    def sound_horn(self):
        print("Honk! Honk!")

    # Method to print information about the ship
    def print_info(self):
        print(f"Ship Name: {self.name}")
        print(f"Length: {self.length} meters")
        print(f"Maximum Speed: {self.max_speed} knots")

# Test the Ship class
if __name__ == "__main__":
    my_ship = Ship("Titanic", 200, 30)
    my_ship.print_info()
    my_ship.sail()
    my_ship.anchor()
    my_ship.sound_horn()
    