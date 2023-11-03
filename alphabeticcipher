def generate_cipher_sequence(keyword):
    unique_letters = set()
    for char in keyword:
        unique_letters.add(char)
    
    for char in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        if char not in unique_letters:
            unique_letters.add(char)
    
    cipher_sequence = ''.join(unique_letters)
    
    return cipher_sequence

def encrypt(plaintext, keyword):
    cipher_sequence = generate_cipher_sequence(keyword)
    
    cipher_dict = {plain: cipher for plain, cipher in zip("ABCDEFGHIJKLMNOPQRSTUVWXYZ", cipher_sequence)}
    
    ciphertext = ''.join(cipher_dict.get(char, char) for char in plaintext.upper())
    
    return ciphertext

def decrypt(ciphertext, keyword):
    cipher_sequence = generate_cipher_sequence(keyword)
    
    cipher_dict = {cipher: plain for plain, cipher in zip("ABCDEFGHIJKLMNOPQRSTUVWXYZ", cipher_sequence)}
    
    plaintext = ''.join(cipher_dict.get(char, char) for char in ciphertext)
    
    return plaintext

keyword = "CIPHER"
plaintext = "abcdefghijklmnopqrstuvwxyz"
ciphertext = encrypt(plaintext, keyword)
decrypted_text = decrypt(ciphertext, keyword)

print("Plaintext:", plaintext)
print("Ciphertext:", ciphertext)
print("Decrypted Text:",Decrypted_text)
