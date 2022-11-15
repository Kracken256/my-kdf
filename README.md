# my-kdf
This code is a custom blazing-fast key derivation function for embedded systems.

This algorithm generated a 1 GB key in 9 seconds on my PC VM. 
This could also be used as a stream cipher.

# Compile
```sh
$ build.sh
```

# Disclaimer
This algorithm has not been audited or approved by anyone. Therefore, there is no guarantee it is secure. If you use this code, you are using it, understanding that it could be unsafe and vulnerable to an attack. As stated in the LICENSE, you, "the user," indemnify me from any liability resulting from this code or anything derived from it. I am not a cryptographer. And although I have done some fundamental analysis on this code, I can not guarantee or even suggest it is secure. The only reason I created it is because it is very fast. Good luck. You are free to modify it as you please. I would appreciate a shout-out if it helps you.