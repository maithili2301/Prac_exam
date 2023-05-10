
def encrypt_text(plaintext,n):
    ans = ""
    for i in range(len(plaintext)):
        ch = plaintext[i]
        
        if ch==" ":
            ans+=" "
        
        elif (ch.isupper()):
            ans += chr((ord(ch) + n-65) % 26 + 65)
     
        
        else:
            ans += chr((ord(ch) + n-97) % 26 + 97)
    
    return ans

plaintext = "ceaser cipher practical"
n = 2
print("Plain Text is : " + plaintext)
print("Shift pattern is : " + str(n))
print("Cipher Text is : " + encrypt_text(plaintext,n))

