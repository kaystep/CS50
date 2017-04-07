import cs50
import sys


def main():
    #Make sure only two arguments are taken at the command line   
    if len(sys.argv) !=2:
        print("Usage: ./caesar <key>")
        exit(1)

    #Convert Argv into an integer for the key    
    k = int(sys.argv[1])
    if (k < 0):
        print("the key must be greater than 0")
        return 1
    else:
        print("plain Text:  ", end="")
        s = cs50.get_string()
        
        
        print("ciphertext:", end="")
        plain_text = s
        
        for i in plain_text:
            if i.isupper():
                print("{}".format(chr((ord(i) - 65 + k)%26 +65)), end="")
            elif i.islower():
                print("{}".format(chr((ord(i) - 97 + k)%26 +97)), end="")
            else:
                print(i, end="")
                

                
if __name__ == "__main__":
    main()
 
#formating so terminal prompt is on a newline  
print("")