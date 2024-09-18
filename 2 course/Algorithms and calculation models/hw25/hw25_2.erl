-module(main).
-export([start/0]).

-define (INPUT_DATA, [665, 666, 661, 661, 657, 660, 661, 656, 656, 652, 659, 651, 656, 657, 652, 654, 646, 651, 652, 647]).

qsort([]) ->
    [];
qsort([Pivot | L]) ->
    LesserPart = [X || X <- L, X < Pivot],
    GreaterPart = [X || X <- L, X >= Pivot],
    qsort(LesserPart) ++ [Pivot] ++ qsort(GreaterPart).
        
print([]) ->
    [];
print([CurrElement | Others]) ->
    io:fwrite("~w ", [CurrElement]), %io:fwrite("~w" ++ " ", [CurrElement]),
    print(Others).

start() ->
    Input = ?INPUT_DATA,
    Output = qsort(Input),
    io:fwrite("input:\n"),
    print(Input),
    io:fwrite("\n"),
    io:fwrite("output:\n"),
    print(Output), 
    io:fwrite("\n").