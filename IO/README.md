# boost I/O

## file system

```
nabeshin@iMacNabeshin IO % g++ -std=c++17 file_system.cpp -lboost_filesystem     
ld: warning: dylib (/usr/local/lib/libboost_filesystem.dylib) was built for newer macOS version (13.0) than being linked (11.0)
nabeshin@iMacNabeshin IO % ./a.out 
File: "a.out"
  path="/Volumes/Thunderbolt3_SSD/workspace/boost_practice/IO/a.out"
  root_path="/", root_name="", parent_path="/Volumes/Thunderbolt3_SSD/workspace/boost_practice/IO", is_absolute=1
File: "file_system.cpp"
  path="/Volumes/Thunderbolt3_SSD/workspace/boost_practice/IO/file_system.cpp"
  root_path="/", root_name="", parent_path="/Volumes/Thunderbolt3_SSD/workspace/boost_practice/IO", is_absolute=1
Dir:   "my_dir"
  path="/Volumes/Thunderbolt3_SSD/workspace/boost_practice/IO/my_dir"
  root_path="/", root_name="", parent_path="/Volumes/Thunderbolt3_SSD/workspace/boost_practice/IO", is_absolute=1
nabeshin@iMacNabeshin IO % 
```

## serialization

```
nabeshin@iMacNabeshin IO % g++ -std=c++17 serialization.cpp -lboost_serialization
ld: warning: dylib (/usr/local/lib/libboost_serialization-mt.dylib) was built for newer macOS version (13.0) than being linked (11.0)
nabeshin@iMacNabeshin IO % ./a.out                                                  
100
3.14
Hello
World
nabeshin@iMacNabeshin IO % 
```