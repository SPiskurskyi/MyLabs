val INPUT_DATA = intArrayOf( 665, 666, 661, 661, 657, 660, 661, 656, 656, 652, 659, 651, 656, 657, 652, 654, 646, 651, 652, 647 )

fun <T : Comparable<T>> List<T>.quickSort(): List<T> = 
    if(size < 2) this
    else {
        val pivot = first()
        val (lesserPart, greaterPart) = drop(1).partition { it <= pivot}
        lesserPart.quickSort() + pivot + greaterPart.quickSort()
    }
    
fun <T : Comparable<T>> List<T>.print(): List<T> = 
    if(size == 0) {
	    this
	}
    else {
        val others = drop(1)
        print(first().toString() + " ")
        others.print()
    }    

fun main(args: Array<String>) {
    //println(INPUT_DATA.toList().quickSort())
    val input = INPUT_DATA.toList()
    val output = input.quickSort()
    println("input:")
    input.print()
    println()
    println("output:")
    output.print()
    println()    
}