def build_playfair_matrix(key):
    key = key.replace("J", "I")  # Replace J with I
    key = "".join(dict.fromkeys(key))  # Remove duplicate letters
    key = key.replace(" ", "").upper()
    
    matrix = [['' for _ in range(5)] for _ in range(5)]
    used_chars = set()
    
    row, col = 0, 0
    for char in key:
        if char not in used_chars:
            matrix[row][col] = char
            used_chars.add(char)
            col += 1
            if col == 5:
                col = 0
                row += 1
    
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    
    for char in alphabet:
        if char not in used_chars:
            matrix[row][col] = char
            used_chars.add(char)
            col += 1
            if col == 5:
                col = 0
                row += 1
    
    return matrix

def find_positions(matrix, char):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return (i, j)
    return None

def encrypt_playfair(plaintext, key):
    matrix = build_playfair_matrix(key)
    plaintext = plaintext.replace("J", "I")
    plaintext = plaintext.upper().replace(" ", "")

    encrypted_text = []
    i = 0

    while i < len(plaintext):
        char1 = plaintext[i]
        i += 1
        if i < len(plaintext):
            char2 = plaintext[i]
            i += 1
        else:
            char2 = 'X'

        if char1 == char2:
            char2 = 'X'

        row1, col1 = find_positions(matrix, char1)
        row2, col2 = find_positions(matrix, char2)

        if row1 == row2:
            encrypted_char1 = matrix[row1][(col1 + 1) % 5]
            encrypted_char2 = matrix[row2][(col2 + 1) % 5]
        elif col1 == col2:
            encrypted_char1 = matrix[(row1 + 1) % 5][col1]
            encrypted_char2 = matrix[(row2 + 1) % 5][col2]
        else:
            encrypted_char1 = matrix[row1][col2]
            encrypted_char2 = matrix[row2][col1]

        encrypted_text.append(encrypted_char1)
        encrypted_text.append(encrypted_char2)

    return "".join(encrypted_text)

def main():
    key = "KEYWORD"
    plaintext = "NANDA KISHORE"

    encrypted_text = encrypt_playfair(plaintext, key)
    print("Original Text: ", plaintext)
    print("Encrypted Text:", encrypted_text)

if __name__ == "__main__":
    main()
