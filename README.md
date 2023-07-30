# Boost study

## install (Mac)

reftered to this page.

* https://www.boost.org/doc/libs/1_82_0/more/getting_started/unix-variants.html
* http://www.kmonos.net/alang/boost/

### install boost

```
% brew install boost
```

### Run sample code

build in VSCode.

```
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
```

```
% g++ ./main.cpp
% ./a.out       
1
3 
4
12 
q
% 
```