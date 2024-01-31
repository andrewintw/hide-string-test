
```
# ./hide_str 
Decoded string: Your.Secret
secret_array: your.secret
SECRET_POINTER: YOUR.SECRET
```

```
# strings ./hide_str | grep -i "your.secret"
YOUR.SECRET
your.secret
```
