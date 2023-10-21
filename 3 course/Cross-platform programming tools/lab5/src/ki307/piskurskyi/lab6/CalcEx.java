package ki307.piskurskyi.lab6;

/**
* Class <code>CalcEx</code> more precise ArithmeticException
* @author Serhii Piskurskyi
* @version 1.0
*/
class CalcEx extends ArithmeticException
{
	public CalcEx(){}
	public CalcEx(String cause)
	{
		super(cause);
	}
}