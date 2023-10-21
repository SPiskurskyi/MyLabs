from matrix_module import get_matrix_size, get_filler_char, create_and_write_matrix

def main():
    size = get_matrix_size()
    filler = get_filler_char()
    create_and_write_matrix(size, filler)

if __name__ == "__main__":
    main()