# calc_module.py

import os
import struct
import math

def writeResTxt(fName, result):
    with open(fName, 'w') as f:
        f.write(str(result))

def readResTxt(fName):
    result = 0.0
    try:
        if os.path.exists(fName):
            with open(fName, 'r') as f:
                result = float(f.read())
        else:
            raise FileNotFoundError(f"File {fName} not found.")
    except FileNotFoundError as e:
        print(e)
    return result

def writeResBin(fName, result):
    with open(fName, 'wb') as f:
        f.write(struct.pack('f', result))

def readResBin(fName):
    result = 0.0
    try:
        if os.path.exists(fName):
            with open(fName, 'rb') as f:
                result = struct.unpack('f', f.read())[0]
        else:
            raise FileNotFoundError(f"File {fName} not found.")
    except FileNotFoundError as e:
        print(e)
    return result

def calculate(x):
    try:
        numerator = math.cos(2 * x)
        denominator = math.cos(3 * x - 1) / math.sin(3 * x - 1)
        result = numerator / denominator
    except ZeroDivisionError:
        print("Error: Division by zero.")
        result = 0.0
    except Exception as e:
        print(f"Error: {e}")
        result = 0.0
    return result
