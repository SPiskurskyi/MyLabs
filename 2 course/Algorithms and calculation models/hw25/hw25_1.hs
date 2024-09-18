import System.IO

input_data = [665, 666, 661, 661, 657, 660, 661, 656, 656, 652, 659, 651, 656, 657, 652, 654, 646, 651, 652, 647]

quicksort :: ( Ord a ) => [ a ] -> [ a ]
quicksort [] = []
quicksort ( x : xs ) =
    let lesserPart =  [ a | a <- xs , a <= x ]
        greaterPart = [ a | a <- xs , a > x ]
    in quicksort lesserPart ++ [ x ] ++ quicksort greaterPart

printElements :: [Int] -> IO()
printElements [] = return ()
printElements (x:xs) = do 
    putStr (show x ++ " ")
    printElements xs

main :: IO ()
main = do 
    let input = input_data 
    let output = quicksort input 
    putStr "input:\n"
    printElements input
    putStr "\n"       
    putStr "output:\n"
    printElements output
    putStr "\n"
