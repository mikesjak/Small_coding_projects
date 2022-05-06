# LoginSystem

### Summary

- This program is a simple login window in terminal.
- It will remember your previous logins so it will be possible to login anytime.
- In this verion, user data are protected by simple XOR cipher.

### How does this XOR work?
- Simply you have to define KEY
- The this cipher uses XOR to encrypt your data
- You can simply choose your KEY or use randomised KEY but you have the same probability that you get the right or the wrong data after decrypt
- For our purposes, we will use your favourite number 0-9 as KEY
##### Example
```md
M xor K = C
C xor K = M
```

### How to run

- Simply clone the repository by
```md
git clone git@github.com:mikesjak/LoginSystem.git
```
- Then compile the code.c by running
```md
cd XOR
g++ -Wall -pedantic code.c -o login.out
```
