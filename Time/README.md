# Date, Time, Timer

## boost::thread

```
nabeshin@iMacNabeshin Time % pwd
/Volumes/Thunderbolt3_SSD/workspace/boost_practice/Time
nabeshin@iMacNabeshin Time % ls /usr/local/Cellar/boost/1.82.0_1/lib | grep libboost_thread
libboost_thread-mt.a
libboost_thread-mt.dylib
nabeshin@iMacNabeshin Time % g++ -std=c++17 progress_display.cpp -lboost_thread-mt
nabeshin@iMacNabeshin Time % ./a.out 

0%   10   20   30   40   50   60   70   80   90   100%
|----|----|----|----|----|----|----|----|----|----|
***************************************************
nabeshin@iMacNabeshin Time % 
```
