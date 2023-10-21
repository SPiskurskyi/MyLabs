package ki307.piskurskyi.lab6;

import java.io.*;
import java.util.*;

/**
 * Class <code>FIOCalc</code> Implements FIOCalc class
 * @author Serhii Piskurskyi
 * @version 1.1
 */
public class FIOCalc {
    private double result;

    public void writeResTxt(String fName) {
        try (PrintWriter f = new PrintWriter(fName)) {
            f.printf("%f ", result);
        } catch (FileNotFoundException ex) {
            System.out.println("Error writing to file: " + ex.getMessage());
        }
    }

    public void readResTxt(String fName) {
        try (Scanner s = new Scanner(new File(fName))) {
            result = s.nextDouble();
        } catch (FileNotFoundException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public void writeResBin(String fName) {
        try (DataOutputStream f = new DataOutputStream(new FileOutputStream(fName))) {
            f.writeDouble(result);
        } catch (FileNotFoundException ex) {
            System.out.println("Error finding file: " + ex.getMessage());
        } catch (IOException ex) {
            System.out.println("Error writing to binary file: " + ex.getMessage());
        }
    }

    public void readResBin(String fName) {
        try (DataInputStream f = new DataInputStream(new FileInputStream(fName))) {
            result = f.readDouble();
        } catch (FileNotFoundException ex) {
            System.out.println("Error finding file: " + ex.getMessage());
        } catch (IOException ex) {
            System.out.println("Error reading from binary file: " + ex.getMessage());
        }
    }

    public void calculate(double x) throws CalcEx {
        double y, radl, radr;
        radl = (2 * x);
        radr = (3 * x - 1);
        try {
            y = (Math.cos(radl) / (1 / Math.tan(radr)));
            if (y == Double.NaN || y == Double.NEGATIVE_INFINITY || y == Double.POSITIVE_INFINITY || Math.tan(radr) == 0 || Math.tan(radr) == Double.NaN) {
                throw new ArithmeticException();
            }
        } catch (ArithmeticException ex) {
            if (Double.isNaN(Math.tan(radr))) {
                throw new CalcEx("Exception reason: Illegal value of X for cotangent calculation");
            } else if (Math.tan(radr) == 0) {
                throw new CalcEx("Exception reason: dividing by zero");
            } else {
                throw new CalcEx("Unknown reason of the exception during exception calculation");
            }
        }
        result = y;
    }

    public double getResult() {
        return result;
    }
}


