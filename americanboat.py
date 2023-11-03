def playfair_decrypt(ciphertext, key):
    def build_playfair_matrix(key):
        key = key.replace("J", "I")
        key_set = set(key)
        alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
        matrix = []
        for letter in key:
            if letter not in matrix:
                matrix.append(letter)
        for letter in alphabet:
            if letter not in matrix:
                matrix.append(letter)
        return [matrix[i:i+5] for i in range(0, 25, 5)]

    def find_positions(matrix, letter):
        for i in range(5):
            for j in range(5):
                if matrix[i][j] == letter:
                    return i, j

    def decrypt_pair(matrix, pair):
        a, b = pair
        a_row, a_col = find_positions(matrix, a)
        b_row, b_col = find_positions(matrix, b)
        if a_row == b_row:
            return matrix[a_row][(a_col - 1) % 5] + matrix[b_row][(b_col - 1) % 5]
        elif a_col == b_col:
            return matrix[(a_row - 1) % 5][a_col] + matrix[(b_row - 1) % 5][b_col]
        else:
            return matrix[a_row][b_col] + matrix[b_row][a_col]

    key = key.upper()
    ciphertext = ciphertext.replace("J", "I").replace(" ", "").upper()
    matrix = build_playfair_matrix(key)
    plaintext = ""
    i = 0
    while i < len(ciphertext):
        if i + 1 < len(ciphertext):
            pair = ciphertext[i:i+2]
            plaintext += decrypt_pair(matrix, pair)
            i += 2
        else:
            # Handle the case where there's an odd number of characters
            plaintext += ciphertext[i]
            i += 1
    return plaintext

ciphertext = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ"
key = "KEY"  # Replace with the Playfair key
plaintext = playfair_decrypt(ciphertext, key)
print(plaintext)
