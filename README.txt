Cryptography and Network Security 1 HW3 by Josh Barthelmess

To compile this code run:
g++ hw3.cpp -o hw3.exe

To run:
./hw3.exe


This code implements the Blum-Goldwasser encryption and decryption 
algorithms for the specific setup given in the assignment description.
The advantage of using the Blum-Goldwasser encryption is that it is 
protected from CPA (chosen plaintext attacks) because it is designed to be 
semantically secure. The unpredictable keystream allows the algorithm to 
protects the encryptions from being the same everytime an encryption is 
requested and the particular encryption method makes the Quadratic Residue
attacks unable to distinguish between messages by confounding confounding 
the Legendre symbol of the message.

As is often the case with protecting against particular attacks, this 
scheme is vulnerable to CCA (chosen ciphertext attacks) because the 
it doesn't verify the validity of the ciphertexts that it is given to 
decrypt (it is not "plaintext aware").  


