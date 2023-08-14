# Concurrent


## interprocess(shared memory, mutex, lock)

```
nabeshin@iMacNabeshin Concurrent % g++ -std=c++17 interprocess.cpp
nabeshin@iMacNabeshin Concurrent % ./a.out 
1 2 3
nabeshin@iMacNabeshin Concurrent % ./a.out
2 4 6
nabeshin@iMacNabeshin Concurrent % ./a.out
3 6 9
nabeshin@iMacNabeshin Concurrent % ./a.out
4 8 12
nabeshin@iMacNabeshin Concurrent % ./a.out
5 10 15
nabeshin@iMacNabeshin Concurrent % ./a.out remove
nabeshin@iMacNabeshin Concurrent % ./a.out
1 2 3
nabeshin@iMacNabeshin Concurrent % ./a.out
2 4 6
nabeshin@iMacNabeshin Concurrent % ./a.out
3 6 9
nabeshin@iMacNabeshin Concurrent % ./a.out remove
nabeshin@iMacNabeshin Concurrent % 
```

## thread

* it continues print "Write something..." until type something.

```
nabeshin@iMacNabeshin Concurrent % g++ -std=c++17 ./thread.cpp -lboost_thread-mt
ld: warning: dylib (/usr/local/lib/libboost_thread-mt.dylib) was built for newer macOS version (13.0) than being linked (11.0)
nabeshin@iMacNabeshin Concurrent % ./a.out                                      
Write something...
Write something...
Write something...acb
Thank you!!! [acb]
nabeshin@iMacNabeshin Concurrent % 
```