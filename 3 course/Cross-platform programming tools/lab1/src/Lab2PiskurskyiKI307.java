import java.io.*;
import java.util.*;
/**
* Клас Lab2PiskurskyiKI-307 реалізує програму до лабораторної роботи №1
*
* @author Serhii Piskurskyi
* @version 1.0
* @since version 1.0
*
*/
public class Lab2PiskurskyiKI307
{
    /**
    * Статичний метод main є точкою входу в програму
    *
    * @param args
    * 
    *
    */
    public static void main(String[] args) throws FileNotFoundException
    {
        int size;
        String filler;
        Scanner in = new Scanner(System.in);
        File dataFile = new File("MyFile.txt");
        PrintWriter fout = new PrintWriter(dataFile);
        System.out.print("Enter size of matrix: ");
        while(true)
        {
        	size = in.nextInt();
        	if(size < 3 ) {
        		System.out.print("The size of the matrix is less than 3\nTry again\t\n");
        		}
        	else {
        		break;
        	}
        }
        in.nextLine();
        System.out.print("\nEnter placeholder char:  ");
        filler = in.nextLine();
        while(true) {
        	if(filler.length() != 1) {
        		System.out.print("fill char must be one, try again:\t");
        		filler = in.nextLine();
        	}
        	else break;
        }
        char[][] arr = new char[size][];
        for (int i = 0; i < size; i++)
        {
            if(i==0 ||i==size-1)
            {
                System.out.println();
                fout.write("\n");
                continue;
            }
            arr[1] = new char[size-1];
            arr[size-2]=new char[size-1];
            arr[i] = new char[size-1];
            for (int j = 1; j < size-1; j++)
                {  
            arr[1][j] = (char)filler.codePointAt(0);//top
            arr[i][1] = (char)filler.codePointAt(0);//left
            arr[size-2][j] = (char)filler.codePointAt(0); //bottom
            arr[i][size-2] = (char)filler.codePointAt(0); //right
            arr[i][j] = (char)filler.codePointAt(0); //middle
            
            System.out.print(arr[i][j]);
            fout.write( arr[i][j]);
                }
                System.out.println();
                fout.write("\n");
        }
        in.close();
        fout.flush();
        fout.close();
    }
}