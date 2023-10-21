package ki307.piskurskyi.lab5;

/**
* Class <code>Calc</code> implements method for cos(2x) / ctg(3x-1) expression
* calculation
* @author Serhii Piskurskyi
* @version 1.0
*/
 public class Calc
{
	/**
	* Method calculates the cos(2x) / ctg(3x-1) expression
	* @param <code>x</code> Angle in degrees
	* @throws CalcException
	*/
	public double calculate(int x) throws CalcEx
	{
		double y, radl, radr;
		radl = (2 * x);
		radr = (3 * x - 1);
		try
		{
			y = (Math.cos(radl) / (1 / Math.tan(radr)));
			// Якщо результат не є числом, то генеруємо виключення
			if (y==Double.NaN || y==Double.NEGATIVE_INFINITY || y==Double.POSITIVE_INFINITY || Math.tan(radr) == 0 || Math.tan(radr) == Double.NaN)
				throw new ArithmeticException(); 
		}
		catch (ArithmeticException ex)
		{
			// створимо виключення вищого рівня з поясненням причини
			// виникнення помилки
			if (Math.tan(radr) == Double.NaN) {
				throw new CalcEx("Exception reason: Illegal value of X for cotangent calculation");
			}
			else if (Math.tan(radr) == 0 ) {
				throw new CalcEx("Exception reason: dividing by zero");
			}
			else {
				throw new CalcEx("Unknown reason of the exception during exception calculation");
			}
		}
		return y;
	}
}