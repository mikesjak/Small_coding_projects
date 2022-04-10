# LoginSystem

### Summary

- This program is a simple login window in terminal.
- It will remember your previous logins so it will be possible to login anytime.
- In this verion, user data are protected by simple Caesar cipher.

### How does this cipher work?
- Simply you have to define KEY
- The this cipher shifts your string by KEY letters in ASCII

##### Example
```md
KEY = 3
abc -> def
```

### How to run

- Simply clone the repository by
```md
git clone git@github.com:mikesjak/LoginSystem.git
```
- Then compile the code.c by running
```md
cd Caesar
g++ -Wall -pedantic code.c -o login.out
```
