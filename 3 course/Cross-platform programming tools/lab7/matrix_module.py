# matrix_module.py

def get_matrix_size():
    try:
        size = int(input("Enter size of matrix: "))
        if size < 3:
            print("The size of the matrix is less than 3\nTry again\t")
        else:
            return size
    except ValueError:
        print("Invalid input. Please enter an integer.")

def get_filler_char():
    filler = input("Enter placeholder char: ")
    if len(filler) != 1:
        print("Fill char must be one, try again:")
    else:
        return filler

def create_and_write_matrix(size, filler):
    with open("MyFile.txt", "w") as fout:
        for i in range(size):
            if i == 0 or i == size - 1:
                print()
                fout.write("\n")
                continue
            row = []
            for j in range(size):
                if j == 0 or j == size - 1:
                    continue
                if i == 1 or i == size - 2 or j == 1 or j == size - 2:
                    row.append(filler)
                else:
                    row.append(filler)
            print("".join(row))
            fout.write("".join(row) + "\n")
