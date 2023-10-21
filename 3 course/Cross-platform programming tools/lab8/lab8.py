import sys
from calc_module import writeResTxt, readResTxt, writeResBin, readResBin, calculate

if __name__ == "__main__":
    try:
        data = float(input("Enter data: "))
        result = calculate(data)
        print(f"Result is: {result}")

        writeResTxt("textRes.txt", result)
        writeResBin("binRes.bin", result)

        print("Result from binary file is: {0}".format(readResBin("binRes.bin")))
        print("Result from text file is: {0}".format(readResTxt("textRes.txt")))
    except FileNotFoundError as e:
        print(e)
        sys.exit(1)
    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit(1)